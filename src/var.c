#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "var.h"

// 建立链表所需长度 
#define LEN1 sizeof(student)
#define LEN2 sizeof(question)

int n,n0,n1;// 全局变量 

// 定义文件指针 
FILE *fp1,*fp2,*fp3,*fp4;
 
// 建立题库链表，用于录入题目
question *creatque()
{
	question *head=NULL,*p1=NULL,*p2=NULL;
	n=0,n0=0,n1=0;
	// 开辟一个新节点 
	printf("请按照下面顺序依次输入信息：\n");
	printf("当题目输入为 # 时结束录入。\n");
	printf("题目 答案（以空格隔开,以回车结束）\n");
	// 初始化 head 为 NULL 避免野指针
	head=NULL;
	// 当题目为 # 时结束链表的建立 
	while (1)
	{
        p1=(question *)malloc(LEN2);
        if (!p1) {
            // 内存分配失败
            return head;
        }
        // 考虑单词长度上限
        scanf("%99s",p1->problem);
        if (!strcmp("#",p1->problem))
        {
            free(p1);
            break;
        }
        scanf("%99s",p1->answer);
		n++;
		// head 固定指向开头后便不再改变  
		if (n==1) head=p1;
		// p2 指向上一个节点
		else p2->next=p1;
		// 更迭 
		p2=p1;
		// 判断题目类型
		if (strlen(p1->answer)==1)
		{
			p1->type=0; // 单填
			n0++;
		}
		else 
		{
			p1->type=1; // 多填
			n1++;
		}
	}
	// 链表末尾指向 NULL 避免野指针 
    if (p2) p2->next=NULL;
	// 计算每道题目的分值 
	float avg0,avg1;
    // 考虑题目数为 0
	avg0=(n0>0)?1.0*100/n0:0;
	avg1=(n1>0)?1.0*100/n1:0;
	// 此处的 p 初始赋值为链表的初始地址 
	question *p;
	p=head;
	// 检查确保链表存在 
	if (head!=NULL)
	{
		// 录入题目分值 
		do 
		{
			if (p->type==0)
			p->score=avg0;
			else if (p->type==1)
			p->score=avg1;
			// p 指向下一个节点的地址 
			p=p->next;
		}while (p!=NULL);
	}
	return head;
} 

// 从文件中提取题库至临时链表
question *RecordQue()
{
	question *head,*p1,*p2;
	n=0,n0=0,n1=0;
	// 保存当前文件位置
	long ori_pos=ftell(fp1);
	// 回到开头
	rewind(fp1);
	// 题头部分
	char tithead[1000];
	fgets(tithead,sizeof(tithead),fp1);
	// 开辟动态存储区
	p1=(question *)malloc(LEN2);
	// 读取第一题
	if (fscanf(fp1,"%d%s%s%f%d",
        &p1->pronum,p1->problem,p1->answer,
        &p1->score,&p1->type)==5)
	{
		n=1;
		head=p1;
		p2=p1;
		// 继续读取
		while (1)
		{
			p1=(question *)malloc(LEN2); 
			if (fscanf(fp1,"%d%s%s%f%d",
                &p1->pronum,p1->problem,p1->answer,
                &p1->score,&p1->type)!=5)
			{
				free(p1);
				break;	
			}
			n++;
			// 判断题目类型
			if (strlen(p1->answer)==1)
			n0++;
			else 
			n1++;
			p2->next=p1;
			p2=p1;	
		} 
		p2->next=NULL; 
	}
	else
	{
		free(p1);
		head=NULL;	
	} 
	// 恢复原状 
	fseek(fp1,ori_pos,SEEK_SET);
	return head; 
} 

// 提取学生作答记录
student *RecordStu()
{
	student *head,*p1,*p2;
	// 保存当前文件位置
	long ori_pos=ftell(fp2);
	// 回到开头
	rewind(fp2);
	// 题头部分
	char tithead[1000];
	fgets(tithead,sizeof(tithead),fp2);
	// 开辟动态存储区
	p1=(student *)malloc(LEN1);
	// 读取第一行做题情况
	if (fscanf(fp2,"%u %s %d %s %d %s %s %f %f %d",
        &p1->StudentID,p1->major,&p1->grade,p1->name,
        &p1->pronum,p1->problem,p1->answer,&p1->score,
        &p1->total_score,&p1->type)==10)
	{
		head=p1;
		p2=p1;
		// 继续读取
		while (1)
		{
			p1=(student *)malloc(LEN1); 
			if (fscanf(fp2,"%u %s %d %s %d %s %s %f %f %d",
                &p1->StudentID,p1->major,&p1->grade,p1->name,
                &p1->pronum,p1->problem,p1->answer,&p1->score,
                &p1->total_score,&p1->type)!=10)
			{
				free(p1);
				break;	
			}
			p2->next=p1;
			p2=p1;	
		} 
		p2->next=NULL; 
	}
	else
	{
		free(p1);
		head=NULL;	
	} 
	// 恢复原状 
	fseek(fp2,ori_pos,SEEK_SET);
	return head; 
} 

// 提取单项填空学生成绩
student *RecordScore_Single()
{
    student *head=NULL,*p1,*last_single=NULL;
    // 当前处理的学生id
    unsigned int current_id=0;
    // 是否为第一个学生
    int is_first_student=1;
    // 保存当前文件位置
    long ori_pos=ftell(fp2);
    // 回到开头
    rewind(fp2);
    // 跳过题头
    char tithead[1000];
    fgets(tithead,sizeof(tithead),fp2);
    while (1)
    {
        // 分配新节点
        p1=(student *)malloc(LEN1);
        if (!p1) {
            // 内存分配失败
            return head;
        }
        if (fscanf(fp2,"%u %s %d %s %d %s %s %f %f %d",
            &p1->StudentID, p1->major, &p1->grade, p1->name,
            &p1->pronum, p1->problem, p1->answer,
            &p1->score, &p1->total_score, &p1->type)!=10)
        {
            free(p1);
            break;
        }
        // 只处理单项填空 (type==0)
        if (p1->type==0)
        {
            // 如果是第一个学生或新学生
            if (is_first_student || current_id!=p1->StudentID)
            {
                // 保存上一个学生的最后一条记录
                if (last_single!=NULL)
                {
                    // 链表为空，将last_single设为head
                    if (head==NULL)
                    {
                        head=last_single;
                        last_single->next=NULL;
                    }
                    else
                    {
                        // 将last_single添加到链表末尾
                        student *temp=head;
                        while(temp->next!=NULL) temp=temp->next;
                        temp->next=last_single;
                        last_single->next=NULL;
                    }
                }
                // 开始处理新学生
                current_id=p1->StudentID;
                // 该学生最后一条记录
                last_single=p1;
                // 设为非第一个学生
                is_first_student=0;
            }
            else
            {
                // 同一个学生，更新最后一条记录
                free(last_single);  // 释放前一条
                last_single=p1;
            }
        }
        else
        {
            free(p1);  // 不是单项填空，释放内存
        }
    }
    // 处理最后一个学生的记录
    if (last_single!=NULL)
    {
        if (head==NULL)
        {
            head=last_single;
            last_single->next=NULL;
        }
        else
        {
            student *temp=head;
            while(temp->next!=NULL) temp=temp->next;
            temp->next=last_single;
            last_single->next=NULL;
        }
    }
    // 恢复原状
    fseek(fp2,ori_pos,SEEK_SET);
    return head;
}

// 提取多项填空学生成绩
student *RecordScore_Mutiple()
{
    student *head=NULL, *p1, *last_multiple=NULL;
    unsigned int current_id=0;
    int is_first_student=1;
    // 保存当前文件位置
    long ori_pos=ftell(fp2);
    // 回到开头
    rewind(fp2);
    // 跳过题头
    char tithead[1000];
    fgets(tithead,sizeof(tithead),fp2);
    while (1)
    {
        // 分配新节点
        p1=(student *)malloc(LEN1);
        if (!p1) {
            // 内存分配失败
            return head;
        }
        if (fscanf(fp2,"%u %s %d %s %d %s %s %f %f %d",
            &p1->StudentID, p1->major, &p1->grade, p1->name,
            &p1->pronum, p1->problem, p1->answer,
            &p1->score, &p1->total_score, &p1->type)!=10)
        {
            free(p1);
            break;
        }
        // 只处理多项填空 (type==1)
        if (p1->type==1)
        {
            // 如果是第一个学生或新学生
            if (is_first_student || current_id!=p1->StudentID)
            {
                // 保存上一个学生的最后一条记录
                if (last_multiple!=NULL)
                {
                    if (head==NULL)
                    {
                        head=last_multiple;
                        last_multiple->next=NULL;
                    }
                    else
                    {
                        // 将last_multiple添加到链表末尾
                        student *temp=head;
                        while(temp->next!=NULL) temp=temp->next;
                        temp->next=last_multiple;
                        last_multiple->next=NULL;
                    }
                }
                // 开始新学生
                current_id=p1->StudentID;
                last_multiple=p1;
                is_first_student=0;
            }
            else
            {
                // 同一个学生，更新最后一条记录
                free(last_multiple);  // 释放前一条
                last_multiple=p1;
            }
        }
        else
        {
            free(p1);  // 不是多项填空，释放内存
        }
    }
    // 处理最后一个学生的记录
    if (last_multiple!=NULL)
    {
        if (head==NULL)
        {
            head=last_multiple;
            last_multiple->next=NULL;
        }
        else
        {
            student *temp=head;
            while(temp->next!=NULL) temp=temp->next;
            temp->next=last_multiple;
            last_multiple->next=NULL;
        }
    }
    // 恢复原状
    fseek(fp2,ori_pos,SEEK_SET);
    return head;
}
