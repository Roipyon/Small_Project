#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "teacher.h"
#include "users.h"
#include "var.h"

// 教师功能菜单 
void TeaFunction()
{
	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	   教师管理系统	 	 ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║	尊敬的教师，欢迎回来！	 ║\n");
	printf("║				 ║\n");
	printf("║	     功能菜单		 ║\n");
	printf("║	┌───────────────┐        ║\n");
	printf("║	│  1.题目管理   │        ║\n");
	printf("║	│  2.成绩管理   │        ║\n");
	printf("║	│  3.返回主菜单 │        ║\n");
	printf("║	└───────────────┘        ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		// 调用题目管理系统函数
		TitleSystem(); 
	}
	else if (flag==2)
	{
		// 调用成绩管理系统函数
		ScoreSystem();
	}
	else if (flag==3)
	{
		// 初始页面 
		PrintSystem();
		return;
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 TeaFunction 函数输出系统界面 
		TeaFunction();
		return;
	} 
}

// 题目管理菜单 
void TitleSystem()
{
	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	   题目管理系统	 	 ║\n");
	printf("╠════════════════════════════════╣\n"); 
	printf("║				 ║\n");
	printf("║	   题目操作菜单	 	 ║\n");
	printf("║	┌───────────────┐        ║\n");
	printf("║	│  1.录入题目   │        ║\n");
	printf("║	│  2.增加题目   │        ║\n");
	printf("║	│  3.删减题目 	│        ║\n");
	printf("║	│  4.返回上一级 │        ║\n");
	printf("║	└───────────────┘        ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		// 调用题目录入函数 
		TitleRecord();
	}
	else if (flag==2)
	{
		// 调用题目添加函数
		TitleAdd();
	}
	else if (flag==3)
	{
		// 调用题目删除函数
		TitleDelete();
	}
	else if (flag==4)
	{
		// 主菜单 
		TeaFunction();
		return;
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 TitleSystem 函数输出系统界面 
		TitleSystem();
		return;
	} 
}

// 成绩管理菜单 
void ScoreSystem()
{
	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	   成绩管理系统	 	 ║\n");
	printf("╠════════════════════════════════╣\n"); 
	printf("║				 ║\n");
	printf("║	   成绩操作菜单	 	 ║\n");
	printf("║	┌───────────────┐        ║\n");
	printf("║	│  1.成绩查询   │        ║\n");
	printf("║	│  2.成绩统计   │        ║\n");
	printf("║	│  3.成绩排序   │        ║\n");
	printf("║	│  4.返回上一级 │        ║\n");
	printf("║	└───────────────┘        ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		// 调用成绩查询函数 
		ScoreFind(); 
	}
	else if (flag==2)
	{
		// 调用成绩统计函数
		ScoreCount();
	}
	else if (flag==3)
	{
		// 调用成绩排序函数
		ScoreSort();
	}
	else if (flag==4)
	{
		// 教师功能菜单  
		TeaFunction(); 
		return;
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 ScoreSystem 函数输出系统界面 
		ScoreSystem();
		return;
	} 
}
// 成绩查询 
void ScoreFind() 
{

	// 前置步骤

	// 先关闭fp2指向的文件，避免造成问题 
	fclose(fp2);
	// 重新以 r+ 的方式打开学生作答文件
	fp2=fopen("stu.txt","r+");
	// 检查文件是否成功打开，如果没有提示学生作答
	if (fp2==NULL)
	{
		printf("文件打开失败！请检查是否有学生作答记录。\n");
		printf("请按任意键返回成绩管理系统。\n");
		getchar();
		getchar();
		ScoreSystem();		
		return;
	}
	student *wait_to_find;
	// 调用 RecordStu 从文件中提取学生作答记录
	wait_to_find=RecordStu();
	// 若地址为空
	if (wait_to_find==NULL)
	{
		printf("学生作答记录为空！请检查是否有学生作答记录。\n");
		printf("请按任意键返回成绩管理系统。\n");
		getchar();
		getchar();
		ScoreSystem(); 
		return; 
	}

	// 菜单界面展示

	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	   成绩查询系统	 	 ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║	  请选择查询方式	 ║\n");
	printf("║				 ║\n");
	printf("║     查看学生的所有作答记录	 ║\n");
	printf("║     ┌───────────────────┐      ║\n");
	printf("║     │  1.按姓名查询     │      ║\n");
	printf("║     │  2.按班级查询     │      ║\n");
	printf("║     │  3.按专业查询     │      ║\n");
	printf("║     │  4.按学号范围查询 │      ║\n");
	printf("║     │  5.返回上一级     │      ║\n");
	printf("║     └───────────────────┘      ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		// 姓名
		FindForName(wait_to_find);
	}
	else if (flag==2)
	{
		// 班级
		FindForGrade(wait_to_find);
	}
	else if (flag==3)
	{
		// 班级
		FindForMajor(wait_to_find);
	}
	else if (flag==4)
	{
		// 学号范围
		FindForIDRange(wait_to_find);
	}
	else if (flag==5)
	{
		// 成绩管理系统 
		ScoreSystem();
		return;
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 ScoreFind 函数输出系统界面 
		ScoreFind();
		return;
	} 
}
// 成绩统计 
void ScoreCount() 
{

	// 前置步骤

	// 先关闭fp1,fp2指向的文件，避免造成问题 
	fclose(fp2);
	// 重新以 r+ 的方式打开学生作答文件
	fp2=fopen("stu.txt","r+");
	// 检查文件是否成功打开，如果没有提示学生作答
	if (fp2==NULL)
	{
		printf("文件打开失败！请检查是否有学生作答记录。\n");
		printf("请按任意键返回成绩管理系统。\n");
		getchar();
		getchar();
		ScoreSystem();		
		return;
	}
	// 这里的调用 RecordQue 是为了确保全局变量 n 得到正确赋值
	question *tmp;
	tmp=RecordQue();
	// 调用 RecordScore 从文件中提取学生作答总分
	student *wait_to_count0,*wait_to_count1;
	wait_to_count0=RecordScore_Single();
	wait_to_count1=RecordScore_Mutiple();
	// 若地址为空
	if (wait_to_count0==NULL || wait_to_count1==NULL)
	{
		printf("学生作答记录为空！请检查是否有学生作答记录。\n");
		printf("请按任意键返回成绩管理系统。\n");
		getchar();
		getchar();
		ScoreSystem(); 
		return; 
	}

	// 菜单界面展示

	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	   成绩统计系统	 	 ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║	  请选择统计方式	 ║\n");
	printf("║				 ║\n");
	printf("║      统计学生的作答总分数	 ║\n");
	printf("║     ┌───────────────────┐      ║\n");
	printf("║     │  1.按班级统计     │      ║\n");
	printf("║     │  2.按专业统计     │      ║\n");
	printf("║     │  3.按学号范围统计 │      ║\n");
	printf("║     │  4.返回上一级     │      ║\n");
	printf("║     └───────────────────┘      ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		printf("单项填空成绩统计结果：\n");
		CountForGrade(wait_to_count0);
		printf("多项填空成绩统计结果：\n");
		CountForGrade(wait_to_count1);
		fclose(fp2);
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();
	}
	else if (flag==2)
	{
		printf("单项填空成绩统计结果：\n");
		CountForMajor(wait_to_count0);
		printf("多项填空成绩统计结果：\n");
		CountForMajor(wait_to_count1);
		fclose(fp2);
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();
	}
	else if (flag==3)
	{
		printf("单项填空成绩统计结果：\n");
		CountForIDRange(wait_to_count0);
		printf("多项填空成绩统计结果：\n");
		CountForIDRange(wait_to_count1);
		fclose(fp2);
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();
	}
	else if (flag==4)
	{
		// 成绩管理系统 
		ScoreSystem();
		return;
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 ScoreCount 函数输出系统界面 
		ScoreCount();
		return;
	} 
}
// 成绩排序 
void ScoreSort()
{
	// 前置步骤

	// 先关闭fp3,fp2指向的文件，避免造成问题 
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	// 重新以 r+ 的方式打开学生作答文件
	fp2=fopen("stu.txt","r+");
	fp3=fopen("sort1.txt","r+");
	fp4=fopen("sort2.txt","r+");
	// 检查文件是否成功打开，如果没有提示学生作答
	if (fp2==NULL)
	{
		printf("文件打开失败！请检查是否有学生作答记录。\n");
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();		
		return;
	}
	// 检查文件是否成功打开，如果没有则创建新文件
	if (fp3==NULL)
	{
		fp3=fopen("sort1.txt","w+");
		printf("文件打开失败！已为您创建sort文件。\n");
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();
		return;
	}
	if (fp4==NULL)
	{
		fp4=fopen("sort2.txt","w+");
		printf("文件打开失败！已为您创建sort文件。\n");
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();
		return;
	}
	fprintf(fp3,"学号\t专业\t班级\t姓名\t总分\t题目类型\n");
	fprintf(fp4,"学号\t专业\t班级\t姓名\t总分\t题目类型\n");
	// 这里的调用 RecordQue 是为了确保全局变量 n,n0,n1 得到正确赋值
	question *tmp;
	tmp=RecordQue();
	// 调用 RecordScore 从文件中提取学生作答总分
	student *wait_to_sort0,*wait_to_sort1;
	wait_to_sort0=RecordScore_Single();
	wait_to_sort1=RecordScore_Mutiple();
	// 若地址为空
	if (wait_to_sort0==NULL)
	{
		printf("学生作答记录为空！请检查是否有学生作答记录。1\n");
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem(); 
		return; 
	}
	if (wait_to_sort1==NULL)
	{
		printf("学生作答记录为空！请检查是否有学生作答记录。2\n");
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem(); 
		return; 
	}

	// 菜单界面展示

	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	   成绩排序系统	 	 ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║	  请选择排序方式	 ║\n");
	printf("║				 ║\n");
	printf("║      排序学生成绩至文件中	 ║\n");
	printf("║       ┌────────────────┐       ║\n");
	printf("║       │  1.按成绩排序  │       ║\n");
	printf("║       │  2.按班级排序  │       ║\n");
	printf("║       │  3.返回上一级  │       ║\n");
	printf("║       └────────────────┘       ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		printf("单项填空成绩排序方式：\n");
		SortForScore(wait_to_sort0);
		printf("多项填空成绩排序方式：\n");
		SortForScore(wait_to_sort1);
		printf("按成绩排序完成！请在 sort1.txt 文件中查看结果。\n");
		fclose(fp2);
		fclose(fp3);
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();
		return;
	}
	else if (flag==2)
	{
		printf("单项填空成绩排序方式：\n");
		SortForGrade(wait_to_sort0);
		printf("多项填空成绩排序方式：\n");
		SortForGrade(wait_to_sort1);
		printf("按班级排序完成！请在 sort2.txt 文件中查看结果。\n");
		fclose(fp2);
		fclose(fp4);
		printf("请按任意键返回成绩管理系统...\n");
		getchar();
		getchar();
		ScoreSystem();
		return;
	}
	else if (flag==3)
	{
		// 成绩管理系统 
		ScoreSystem();
		return;
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 ScoreSort 函数输出系统界面 
		ScoreSort();
		return;
	} 
}

// 题目录入函数 
void TitleRecord()
{
	// 先关闭fp1指向的文件，避免造成问题 
	fclose(fp1);
	// 重新以 r+ 的方式打开题库文件
	fp1=fopen("timu.txt","r+"); 
	// 检查文件是否成功打开，如果没有则创建新文件
	if (fp1==NULL)
	{
		printf("文件打开失败！已为您创建新文件。\n");
		fp1=fopen("timu.txt","w+");
		if (fp1!=NULL) 
		{
			// 回到录入题目系统 
			TitleRecord(); 
			return;
		}
		else 
		{
			printf("文件创建失败！现在返回主菜单...\n");
			// 返回教师功能菜单 
			TeaFunction();
			return;
		}
	}
	// 定义临时题库指针用于输出 
	question *p_rec,*p_check;
	// 检查是否已经有录入题目
	p_check=RecordQue();
	// 存在题库
	if (p_check!=NULL)
	{
		printf("╔════════════════════════════════════════════════════╗\n");
		printf("║题库中已存在题目，请前往增加或删除题目功能进行操作。║\n");
		printf("║          现在按下任意键返回题目管理菜单...	     ║\n");
		printf("╚════════════════════════════════════════════════════╝\n");
		getchar();
		getchar();
		TitleSystem();
		return;
	}
	printf("题库打开成功！现在可以开始录入。\n\n");
	// 调用 creatque 创建题库链表
	p_rec=creatque();
	// 当前执行操作但是没有录入题目的情况
	if (p_rec==NULL)
	{
		printf("未录入任何题目！现在按下任意键返回主菜单...\n");
		// 关闭文件 
		fclose(fp1);
		// 再次以 r+ 的形式打开，以供其他函数调用 
		fp1=fopen("timu.txt","r+");
		getchar();
		// 返回教师功能菜单 
		TeaFunction(); 
		return;
	} 
	// 输出至 timu.txt 
	int count=1; 
	fprintf(fp1,"题号\t题目\t答案\t分值\t题目类型\n");
	while (p_rec!=NULL)
	{
		fprintf(fp1,"%d\t%s\t%s\t%f\t%d\n",count,p_rec->problem,p_rec->answer,p_rec->score,p_rec->type);
		p_rec=p_rec->next; 
		count++;
	}
	// 输出后刷新缓冲区 
	fflush(fp1);
	printf("题目录入完毕！你当前已录入 %d 道题目。\n",count-1);
	printf("请按下任意键返回主菜单。\n");
	// 关闭文件 
	fclose(fp1);
	// 再次以 r+ 的形式打开，以供其他函数调用 
	fp1=fopen("timu.txt","r+"); 
	getchar();
	getchar();
	// 返回教师功能菜单 
	TeaFunction();
	return;
}

// 题目增加函数 
void TitleAdd()
{
	// 先关闭fp1指向的文件，避免造成问题 
	fclose(fp1);
	// 重新以 r+ 的方式打开题库文件
	fp1=fopen("timu.txt","r+"); 
	// 检查文件是否成功打开，如果没有提示录入题目 
	if (fp1==NULL)
	{
		printf("文件打开失败！请检查您是否录入过题目。\n");
		printf("请按任意键转到题目录入系统...\n");
		getchar();
		getchar();
		TitleRecord();	
		return;
	}
	// 待操作题库 
	question *wait_to_add;
	// 调用 RecordQue 从文件中提取题库 
	wait_to_add=RecordQue();
	// 若地址为空 
	if (wait_to_add==NULL)
	{
		printf("题库为空！请先录入题目。\n");
		printf("请按任意键转到题目录入系统...\n");
		getchar();
		getchar();
		TitleRecord(); 
		return; 
	} 
	printf("当前题库中的题目数量为：%d\n",n);
	printf("题号\t题目\t答案\n");
	// 用于输出题库 
	question *tmp;
	tmp=wait_to_add;
	while (tmp!=NULL)
	{
		printf("%d\t%s\t%s\n",tmp->pronum,tmp->problem,tmp->answer);
		tmp=tmp->next;
	}
	printf("\n");
	// 定义需要添加题目的位置 
	int loc;
	printf("请输入需要添加题目的位置：\n");
	printf("（输入0则表示在最前面添加）\n");
	scanf("%d",&loc);
	// 定义临时数组存储新增信息
	char problem[100],answer[100];
	printf("请按照下面顺序依次输入信息：\n");
	printf("题目 答案（以空格隔开）\n");
	// 考虑单词，设置长度上限 
	scanf("%99s",problem);
	scanf("%99s",answer);
	// 创建新节点
	question *new_p;
	new_p=(question *)malloc(sizeof(question));
	// 将输入的临时题目和答案录入节点 
	strcpy(new_p->problem,problem);
	strcpy(new_p->answer,answer);
	// 判断题目类型
	if (strlen(new_p->answer)==1)
	{
		new_p->type=0; // 单填
	}
	else 
	{
		new_p->type=1; // 多填
	}
	// 添加过程
	if (loc==0)
	{
		// 以前的首地址作为新节点的 next 
		new_p->next=wait_to_add;
		// 新节点作为首地址 
		wait_to_add=new_p;
	} 
	else
	{
		// 寻找位置
		tmp=wait_to_add;
		// 非空指针且非指定位置 
		while (tmp!=NULL && tmp->pronum!=loc) 
		{
			// 转向下一个节点 
			tmp=tmp->next;
		}
		// 此时已经找到位置 
		if (tmp!=NULL)
		{
			// 新节点 next 指向前一个 next 
			// 相当于节点继承 
			new_p->next=tmp->next;
			// 前一个 next 变为新节点地址 
			tmp->next=new_p;
		}
		else
		{
			// 没找到，重新定回 
			tmp=wait_to_add;
			// 直接找到最后 
			while (tmp->next!=NULL)
			{
				tmp=tmp->next;
			}
			// 最后插入 
			tmp->next=new_p;
			new_p->next=NULL;
			printf("未找到目标位置！已为您添加到题库末尾。\n");
		} 
	}
	// 重新编号
	int count=0,n0=0,n1=0;
	tmp=wait_to_add;
	while (tmp!=NULL) 
	{
		// 判断题目类型
		if (strlen(tmp->answer)==1)
		{
			tmp->type=0; // 单填
			n0++;
		}
		else 
		{
			tmp->type=1; // 多填
			n1++;
		}
		count++;
		// 编号即题号 
		tmp->pronum=count;
		// 下一个节点 
		tmp=tmp->next;
	}
	// 计算每道题目的分值 
	float avg0,avg1;
    // 考虑题目数为 0
	avg0=(n0>0)?1.0*100/n0:0;
	avg1=(n1>0)?1.0*100/n1:0;
	tmp=wait_to_add;
	while (tmp!=NULL)
	{
		if (tmp->type==0)
			tmp->score=avg0;
		else if (tmp->type==1)
			tmp->score=avg1;
		tmp=tmp->next;	
	} 
	// 写回文件
	fclose(fp1);
	fp1=fopen("timu.txt","w");
	fprintf(fp1,"题号\t题目\t答案\t分值\t题目类型\n");
	tmp=wait_to_add;
	while (tmp!=NULL)
	{
		fprintf(fp1,"%d\t%s\t%s\t%f\t%d\n", 
        tmp->pronum,tmp->problem,tmp->answer,tmp->score,tmp->type);
        tmp=tmp->next;
	}
	fclose(fp1);
	// 释放临时题库 
	tmp=wait_to_add;
	while (tmp!=NULL)
	{
		// 存放当前的地址
		question *tep=tmp;
		// 指向下一个 
		tmp=tmp->next;
		// 再将当前地址释放 
		free(tep); 
	}
	// 重新打开以供其他文件使用
	fp1=fopen("timu.txt","r+");
	printf("添加成功！\n");
	printf("当前题库中的题目数量为：%d\n",count); 
	printf("请按任意键返回主菜单...\n");
	getchar();
	getchar();
	TeaFunction(); 
	return;
	//output(wait_to_add);
}

// 题目删除函数
void TitleDelete()
{
	// 先关闭fp1指向的文件，避免造成问题 
	fclose(fp1);
	// 重新以 r+ 的方式打开题库文件
	fp1=fopen("timu.txt","r+"); 
	// 检查文件是否成功打开，如果没有提示录入题目 
	if (fp1==NULL)
	{
		printf("文件打开失败！请检查您是否录入过题目。\n");
		printf("请按任意键转到题目录入系统...\n");
		getchar();
		getchar();
		// 直接进入题库录入系统 
		TitleRecord();		
		return;
	}
	// 待操作题库 
	question *wait_to_del;
	// 调用 RecordQue 从文件中提取题库 
	wait_to_del=RecordQue();
	// 若地址为空 
	if (wait_to_del==NULL)
	{
		printf("题库为空！请先录入题目。\n");
		printf("请按任意键转到题目录入系统...\n");
		getchar();
		getchar();
		TitleRecord(); 
		return; 
	} 
	printf("当前题库中的题目数量为：%d\n",n);
	printf("题号\t题目\t答案\n");
	// 用于输出题库 
	question *tmp;
	tmp=wait_to_del;
	while (tmp!=NULL)
	{
		printf("%d\t%s\t%s\n",tmp->pronum,tmp->problem,tmp->answer);
		tmp=tmp->next;
	}
	printf("\n");
	// 定义需要删除题目的位置 
	int loc;
	// 用于保留上一次的指针 
	question *pre; 
	printf("请输入需要删除题目的位置：\n");
	scanf("%d",&loc);
	// 删除过程
	tmp=wait_to_del;
	pre=NULL; 
	// 寻找过程 
	while (tmp!=NULL && tmp->pronum!=loc)
	{
		// 保留tmp指针
		pre=tmp;
		tmp=tmp->next;
	}
	// tmp指到最后面，也就是找不到指定位置 
	if (tmp==NULL)
	{
		printf("未找到指定位置！\n");
	} 
	else 
	{
		// 删除节点
		if (pre==NULL)
		{
			// 位置在头节点
			wait_to_del=tmp->next;	
		} 
		else
		{
			// 前一个的 next 直接指向当前的 next 
			pre->next=tmp->next;
		}
		free(tmp);
		// 题目数量减少 
		n--;
		printf("指定题目删除成功！\n");
		// 重新编号
		int count=0,n0=0,n1=0;
		tmp=wait_to_del;
		while (tmp!=NULL) 
		{
			// 判断题目类型
			if (strlen(tmp->answer)==1)
			{
				tmp->type=0; // 单填
				n0++;
			}
			else 
			{
				tmp->type=1; // 多填
				n1++;
			}
			count++;
			// 编号即题号 
			tmp->pronum=count;
			// 下一个节点 
			tmp=tmp->next;
		}
		// 计算每道题目的分值 
		float avg0,avg1;
	    // 考虑题目数为 0
		avg0=(n0>0)?1.0*100/n0:0;
		avg1=(n1>0)?1.0*100/n1:0;
		tmp=wait_to_del;
		while (tmp!=NULL)
		{
			if (tmp->type==0)
				tmp->score=avg0;
			else if (tmp->type==1)
				tmp->score=avg1;
			tmp=tmp->next;	
		} 
	}
	// 写回文件
	fclose(fp1);
	fp1=fopen("timu.txt","w");
	fprintf(fp1,"题号\t题目\t答案\t分值\t题目类型\n");
	tmp=wait_to_del;
	while (tmp!=NULL)
	{
		fprintf(fp1,"%d\t%s\t%s\t%f\t%d\n", 
        tmp->pronum,tmp->problem,tmp->answer,tmp->score,tmp->type);
        tmp=tmp->next;
	}
	fclose(fp1);
	// 释放临时题库 
	tmp=wait_to_del;
	while (tmp!=NULL)
	{
		// 存放当前的地址
		question *tep=tmp;
		// 指向下一个 
		tmp=tmp->next;
		// 再将当前地址释放 
		free(tep); 
	}
	// 重新打开以供其他文件使用
	fp1=fopen("timu.txt","r+");
	printf("当前题库中的题目数量为：%d\n",n); 
	printf("请按任意键返回主菜单...\n");
	getchar();
	getchar();
	TeaFunction(); 
	return;
	//output(wait_to_del);
} 
// 按姓名查询 
void FindForName(student *wait_to_find)
{
	printf("请输入需要查询的学生姓名：\n");
	char target_name[100];
	scanf("%s",target_name);
	student *tmp;
	int found=0;
	tmp=wait_to_find;
	printf("========================================================================================================================\n");
	printf("学生 %s 作答记录如下：\n",target_name);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("学号\t\t专业\t班级\t姓名\t编号\t题目\t答案\t分值\t\t总分\t\t题目类型\n");
	while (tmp!=NULL)
	{
		if (strcmp(tmp->name,target_name)==0)
		{
			found=1;
			printf("%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t",
			tmp->StudentID,tmp->major,tmp->grade,tmp->name,
			tmp->pronum,tmp->problem,tmp->answer,
			tmp->score,tmp->total_score);
			if (tmp->type==0)
				printf("单填题\n");
			else if (tmp->type==1)
				printf("多填题\n");
		}
		tmp=tmp->next;
	}
	printf("========================================================================================================================\n");
	if (found==0)
		printf("未找到该学生的作答记录！\n");
	fclose(fp2);
	printf("请按任意键返回成绩管理系统...\n");
	getchar();
	getchar();
	ScoreSystem();
	return;
}
// 按班级查询 
void FindForGrade(student *wait_to_find)
{
	printf("请输入需要查询的班级号：\n");
	int target_grade;
	scanf("%d",&target_grade);
	student *tmp;
	int found=0;
	tmp=wait_to_find;
	printf("========================================================================================================================\n");
	printf("班级 %d 学生作答记录如下：\n",target_grade);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("学号\t\t专业\t班级\t姓名\t编号\t题目\t答案\t分值\t\t总分\t\t题目类型\n");
	while (tmp!=NULL)
	{
		if (tmp->grade==target_grade)
		{
			found=1;
			printf("%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t",
			tmp->StudentID,tmp->major,tmp->grade,tmp->name,
			tmp->pronum,tmp->problem,tmp->answer,
			tmp->score,tmp->total_score);
			if (tmp->type==0)
				printf("单填题\n");
			else if (tmp->type==1)
				printf("多填题\n");
		}
		tmp=tmp->next;
	}
	printf("========================================================================================================================\n");
	if (found==0)
		printf("未找到该班级的作答记录！\n");
	fclose(fp2);
	printf("请按任意键返回成绩管理系统...\n");
	getchar();
	getchar();
	ScoreSystem();
	return;
}
// 按专业查询 
void FindForMajor(student *wait_to_find)
{
	printf("请输入需要查询的专业：\n");
	char target_major[1000];
	scanf("%s",target_major);
	student *tmp;
	int found=0;
	tmp=wait_to_find;
	printf("========================================================================================================================\n");
	printf(" %s 专业学生作答记录如下：\n",target_major);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("学号\t\t专业\t班级\t姓名\t编号\t题目\t答案\t分值\t\t总分\t\t题目类型\n");
	while (tmp!=NULL)
	{
		if (strcmp(tmp->major,target_major)==0)
		{
			found=1;
			printf("%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t",
			tmp->StudentID,tmp->major,tmp->grade,tmp->name,
			tmp->pronum,tmp->problem,tmp->answer,
			tmp->score,tmp->total_score);
			if (tmp->type==0)
				printf("单填题\n");
			else if (tmp->type==1)
				printf("多填题\n");
		}
		tmp=tmp->next;
	}
	printf("========================================================================================================================\n");
	if (found==0)
		printf("未找到该专业的作答记录！\n");
	fclose(fp2);
	printf("请按任意键返回成绩管理系统...\n");
	getchar();
	getchar();
	ScoreSystem();
	return;
}
// 按学号范围查询 
void FindForIDRange(student *wait_to_find)
{
	printf("请输入需要查询的学号范围（起始学号 结束学号）：\n");
	unsigned int start_id,end_id;
	scanf("%u%u",&start_id,&end_id);
	student *tmp;
	int found=0;
	tmp=wait_to_find;
	printf("========================================================================================================================\n");
	printf("学号从 %u 到 %u 学生作答记录如下：\n",start_id,end_id);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("学号\t\t专业\t班级\t姓名\t编号\t题目\t答案\t分值\t\t总分\t\t题目类型\n");
	while (tmp!=NULL)
	{
		if (tmp->StudentID>=start_id && tmp->StudentID<=end_id)
		{
			found=1;
			printf("%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t",
			tmp->StudentID,tmp->major,tmp->grade,tmp->name,
			tmp->pronum,tmp->problem,tmp->answer,
			tmp->score,tmp->total_score);
			if (tmp->type==0)
				printf("单填题\n");
			else if (tmp->type==1)
				printf("多填题\n");
		}
		tmp=tmp->next;
	}
	printf("========================================================================================================================\n");
	if (found==0)
		printf("未找到该学号范围内的作答记录！\n");
	fclose(fp2);
	printf("请按任意键返回成绩管理系统...\n");
	getchar();
	getchar();
	ScoreSystem();
	return;
}
// 按班级统计 
void CountForGrade(student *wait_to_count)
{
	printf("\n");
	printf("请输入需要统计的班级号：\n");
	int target_grade;
	scanf("%d",&target_grade);
	student *tmp;
	// 学生数量 
	int student_count=0;
	// 总分 
	float total_score=0.0;
	// 存储分数段 0-59,60-69,70-79,80-89,90-100
	int score_segment[5]={0}; 
	tmp=wait_to_count;
	printf("=========================================================================\n");
	printf("班级 %d 学生作答成绩如下：\n",target_grade);
	printf("-------------------------------------------------------------------------\n");
	printf("学号\t\t专业\t班级\t姓名\t总分\t\t题目类型\n");
	while (tmp!=NULL)
	{
		if (tmp->grade==target_grade)
		{
			printf("%u\t%s\t%d\t%s\t%f\t",tmp->StudentID,tmp->major,tmp->grade,tmp->name,tmp->total_score);
			if (tmp->type==0)
				printf("单项填空\n");
			else if (tmp->type==1)
				printf("多项填空\n");
			student_count++;
			total_score+=tmp->total_score;
			// 统计分数段
			if (tmp->total_score<60 && tmp->total_score>=0)
				score_segment[0]++;
			else if (tmp->total_score<70)
				score_segment[1]++;
			else if (tmp->total_score<80)
				score_segment[2]++;
			else if (tmp->total_score<90)
				score_segment[3]++;
			else if (tmp->total_score<=100)
				score_segment[4]++;
		}
		tmp=tmp->next;
	}
	printf("=========================================================================\n");
	if (student_count==0)
	{
		printf("未找到该班级的作答记录！\n");
	}
	else 
	{
		printf("========================================\n");
        printf("班级 %d 学生成绩统计结果：\n", target_grade);
        printf("----------------------------------------\n");
        printf("学生总数为：%d 人\n", student_count);
        printf("平均分为：%.2f 分\n", total_score/student_count);
        printf("分数段分布：\n");
        printf("90-100分：%d 人 (%.1f%%)\n", 
               score_segment[4], score_segment[4]*100.0/student_count);
        printf("80-89分： %d 人 (%.1f%%)\n", 
               score_segment[3], score_segment[3]*100.0/student_count);
        printf("70-79分： %d 人 (%.1f%%)\n", 
               score_segment[2], score_segment[2]*100.0/student_count);
        printf("60-69分： %d 人 (%.1f%%)\n", 
               score_segment[1], score_segment[1]*100.0/student_count);
        printf("0-59分：  %d 人 (%.1f%%)\n", 
               score_segment[0], score_segment[0]*100.0/student_count);
        printf("========================================\n\n");
	}
	printf("\n");
	return;
}
// 按专业统计 
void CountForMajor(student *wait_to_count)
{
	printf("\n");
	printf("请输入需要统计的专业：\n");
	char target_major[1000];
	scanf("%s",target_major);
	student *tmp;
	int student_count=0;
	float total_score=0.0;
	// 存储分数段 0-59,60-69,70-79,80-89,90-100
	int score_segment[5]={0};
	tmp=wait_to_count;
	printf("=========================================================================\n");
	printf(" %s 专业学生作答成绩如下：\n",target_major);
	printf("-------------------------------------------------------------------------\n");
	printf("学号\t\t专业\t班级\t姓名\t总分\t\t题目类型\n");
	while (tmp!=NULL)
	{
		if (strcmp(tmp->major,target_major)==0)
		{
			printf("%u\t%s\t%d\t%s\t%f\t",tmp->StudentID,tmp->major,tmp->grade,tmp->name,tmp->total_score);
			if (tmp->type==0)
				printf("单项填空\n");
			else if (tmp->type==1)
				printf("多项填空\n");
			student_count++;
			total_score+=tmp->total_score;
			// 统计分数段
			if (tmp->total_score<60 && tmp->total_score>=0)
				score_segment[0]++;
			else if (tmp->total_score<70)
				score_segment[1]++;
			else if (tmp->total_score<80)
				score_segment[2]++;
			else if (tmp->total_score<90)
				score_segment[3]++;
			else if (tmp->total_score<=100)
				score_segment[4]++;
		}
		tmp=tmp->next;
	}
	printf("=========================================================================\n");
	if (student_count==0)
	{
		printf("未找到该专业的作答记录！\n");
	}
	else 
	{
		printf("========================================\n");
        printf(" %s 专业学生成绩统计结果：\n",target_major);
        printf("----------------------------------------\n");
        printf("学生总数为：%d 人\n", student_count);
        printf("平均分为：%.2f 分\n", total_score/student_count);
        printf("分数段分布：\n");
        printf("90-100分：%d 人 (%.1f%%)\n", 
               score_segment[4], score_segment[4]*100.0/student_count);
        printf("80-89分： %d 人 (%.1f%%)\n", 
               score_segment[3], score_segment[3]*100.0/student_count);
        printf("70-79分： %d 人 (%.1f%%)\n", 
               score_segment[2], score_segment[2]*100.0/student_count);
        printf("60-69分： %d 人 (%.1f%%)\n", 
               score_segment[1], score_segment[1]*100.0/student_count);
        printf("0-59分：  %d 人 (%.1f%%)\n", 
               score_segment[0], score_segment[0]*100.0/student_count);
        printf("========================================\n\n");
	}
	printf("\n");
	return;
}
// 按学号范围统计 
void CountForIDRange(student *wait_to_count)
{
	printf("\n");
	printf("请输入需要统计的学号范围（起始学号 结束学号）：\n");
	unsigned int start_id,end_id;
	scanf("%u%u",&start_id,&end_id);
	student *tmp;
	int student_count=0;
	float total_score=0.0;
	// 存储分数段 0-59,60-69,70-79,80-89,90-100
	int score_segment[5]={0};
	tmp=wait_to_count;
	printf("=========================================================================\n");
	printf("学号从 %u 到 %u 学生作答成绩如下：\n",start_id,end_id);
	printf("-------------------------------------------------------------------------\n");
	printf("学号\t\t专业\t班级\t姓名\t总分\t\t题目类型\n");
	while (tmp!=NULL)
	{
		if (tmp->StudentID>=start_id && tmp->StudentID<=end_id)
		{
			printf("%u\t%s\t%d\t%s\t%f\t",tmp->StudentID,tmp->major,tmp->grade,tmp->name,tmp->total_score);
			if (tmp->type==0)
				printf("单项填空\n");
			else if (tmp->type==1)
				printf("多项填空\n");
			student_count++;
			total_score+=tmp->total_score;
			// 统计分数段
			if (tmp->total_score<60 && tmp->total_score>=0)
				score_segment[0]++;
			else if (tmp->total_score<70)
				score_segment[1]++;
			else if (tmp->total_score<80)
				score_segment[2]++;
			else if (tmp->total_score<90)
				score_segment[3]++;
			else if (tmp->total_score<=100)
				score_segment[4]++;
		}
		tmp=tmp->next;
	}
	printf("=========================================================================\n");
	if (student_count==0)
	{
		printf("未找到该学号范围内的作答记录！\n");
	}
	else 
	{
		printf("=============================================\n");
        printf("学号从 %u 到 %u 学生成绩统计结果：\n", start_id,end_id);
        printf("---------------------------------------------\n");
        printf("学生总数为：%d 人\n", student_count);
        printf("平均分为：%.2f 分\n", total_score/student_count);
        printf("分数段分布：\n");
        printf("90-100分：%d 人 (%.1f%%)\n", 
               score_segment[4], score_segment[4]*100.0/student_count);
        printf("80-89分： %d 人 (%.1f%%)\n", 
               score_segment[3], score_segment[3]*100.0/student_count);
        printf("70-79分： %d 人 (%.1f%%)\n", 
               score_segment[2], score_segment[2]*100.0/student_count);
        printf("60-69分： %d 人 (%.1f%%)\n", 
               score_segment[1], score_segment[1]*100.0/student_count);
        printf("0-59分：  %d 人 (%.1f%%)\n", 
               score_segment[0], score_segment[0]*100.0/student_count);
        printf("=============================================\n\n");
	}
	printf("\n");
	return;
}
// 按成绩排序 
void SortForScore(student *wait_to_sort)
{
	// 待排序链表复制到数组中
	int count=0;
	student *tmp;
	tmp=wait_to_sort;
	// 计算学生数量
	while (tmp!=NULL)
	{
		count++;
		tmp=tmp->next;
	}
	// 创建学生指针数组
	student **stu_arr;
	stu_arr=(student **)malloc(count*sizeof(student *));
	tmp=wait_to_sort;
	for (int i=0;i<count;i++)
	{
		stu_arr[i]=tmp;
		tmp=tmp->next;
	}
	int flag;
	printf("1.从小到大排序\n");
	printf("2.从大到小排序\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		// 冒泡排序
		for (int i=0;i<count-1;i++)
		{
			for (int j=0;j<count-1-i;j++)
			{
				if (stu_arr[j]->total_score>stu_arr[j+1]->total_score)
				{
					student *tep=stu_arr[j];
					stu_arr[j]=stu_arr[j+1];
					stu_arr[j+1]=tep;
				}
			}
		}
	}
	else if (flag==2)
	{
		// 冒泡排序
		for (int i=0;i<count-1;i++)
		{
			for (int j=0;j<count-1-i;j++)
			{
				if (stu_arr[j]->total_score<stu_arr[j+1]->total_score)
				{
					student *tep=stu_arr[j];
					stu_arr[j]=stu_arr[j+1];
					stu_arr[j+1]=tep;
				}
			}
		}
	}
	else
	{
		printf("无效数字。\n");
		return;
	}
	// 输出排序结果到 sort1.txt
	for (int i=0;i<count;i++)
	{
		fprintf(fp3,"%u\t%s\t%d\t%s\t%f\t",
		stu_arr[i]->StudentID,stu_arr[i]->major,
		stu_arr[i]->grade,stu_arr[i]->name,
		stu_arr[i]->total_score);
		if (stu_arr[i]->type==0)
			fprintf(fp3,"单项填空\n");
		else if (stu_arr[i]->type==1)
			fprintf(fp3,"多项填空\n");
	}
	fflush(fp3);
	free(stu_arr);
	return;
}
// 按班级排序 
void SortForGrade(student *wait_to_sort)
{
	// 待排序链表复制到数组中
	int count=0;
	student *tmp;
	tmp=wait_to_sort;
	// 计算学生数量
	while (tmp!=NULL)
	{
		count++;
		tmp=tmp->next;
	}
	// 创建学生指针数组
	student **stu_arr;
	stu_arr=(student **)malloc(count*sizeof(student *));
	tmp=wait_to_sort;
	for (int i=0;i<count;i++)
	{
		stu_arr[i]=tmp;
		tmp=tmp->next;
	}
	int flag;
	printf("1.从小到大排序\n");
	printf("2.从大到小排序\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		// 冒泡排序
		for (int i=0;i<count-1;i++)
		{
			for (int j=0;j<count-1-i;j++)
			{
				if (stu_arr[j]->grade>stu_arr[j+1]->grade)
				{
					student *tep=stu_arr[j];
					stu_arr[j]=stu_arr[j+1];
					stu_arr[j+1]=tep;
				}
			}
		}
	}
	else if (flag==2)
	{
		// 冒泡排序
		for (int i=0;i<count-1;i++)
		{
			for (int j=0;j<count-1-i;j++)
			{
				if (stu_arr[j]->grade<stu_arr[j+1]->grade)
				{
					student *tep=stu_arr[j];
					stu_arr[j]=stu_arr[j+1];
					stu_arr[j+1]=tep;
				}
			}
		}
	}
	else
	{
		printf("无效数字。\n");
		return;
	}
	// 输出排序结果到 sort2.txt
	for (int i=0;i<count;i++)
	{
		fprintf(fp4,"%u\t%s\t%d\t%s\t%f\t",
		stu_arr[i]->StudentID,stu_arr[i]->major,
		stu_arr[i]->grade,stu_arr[i]->name,
		stu_arr[i]->total_score);
		if (stu_arr[i]->type==0)
			fprintf(fp4,"单项填空\n");
		else if (stu_arr[i]->type==1)
			fprintf(fp4,"多项填空\n");
	}
	fflush(fp4);
	free(stu_arr);
	return;
}
