#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "student.h"
#include "users.h"
#include "var.h"

void StuFunction(void)
{
	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	   学生练习系统	 	 ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║	亲爱的同学，欢迎您！	 ║\n");
	printf("║				 ║\n");
	printf("║	     功能菜单		 ║\n");
	printf("║	┌───────────────┐        ║\n");
	printf("║	│  1.单项填空   │        ║\n");
	printf("║	│  2.多项填空   │        ║\n");
	printf("║	│  3.返回主菜单 │        ║\n");
	printf("║	└───────────────┘        ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		SingleAnswer();
	}
	else if (flag==2)
	{
		MultiAnswer();
	}
	else if (flag==3)
	{
		PrintSystem();
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 StuFunction 函数输出系统界面 
		StuFunction();
		return;
	} 
}

// 单项填空 
void SingleAnswer()
{
	fclose(fp1);
	fclose(fp2);
	// 重新以 r+ 的方式打开题库文件
	fp1=fopen("timu.txt","r+");
	// 以 a+ 的形式打开学生作答文件
	fp2=fopen("stu.txt","a+");
	// 检查文件是否成功打开，如果没有提示录入题目
	if (fp1==NULL)
	{
		printf("文件打开失败！请联系教师是否录入过题目。\n");
		getchar();
		getchar();
		StuFunction();
		return; 
	}
	unsigned int StudentID;
	char major[100];
	int grade;
	char name[100];
	char answer[100];
	int type=0;
	float score=0.0;
	printf("请按照下面顺序依次输入信息：\n");
	printf("学号 专业 班级 姓名（以空格隔开）\n");
	scanf("%u%s%d%s",&StudentID,major,&grade,name);
	question *title;
	// 从文件中提取题库 
	title=RecordQue();
	if (title==NULL)
	{
		printf("题库为空！请联系教师录入题目。\n");
		printf("请按任意键返回学生主菜单...\n");
		// 关闭文件
		fclose(fp1);
		// 再次以 r+ 的形式打开，以供其他函数调用
		fp1=fopen("timu.txt","r+");
		getchar();
		getchar();
		// 返回学生功能菜单
		StuFunction();
		return;
	}
	printf("开始答题！\n");
	printf("请输入你的答案并按下回车提交。\n");
	printf("题号 题目\n");
	while (title!=NULL)
	{
		if (title->type!=0)
		{
			title=title->next;
			continue;
		}
		printf("%d %s\n",title->pronum,title->problem);
		scanf("%99s",answer);
		fseek(fp2,0,SEEK_END);
		if (!strcmp(answer,title->answer))
		{
			printf("回答正确！\n");
			score+=title->score;
			fprintf(fp2,"%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t%d\n",
			StudentID,major,grade,name,title->pronum,title->problem,
			answer,title->score,score,title->type);
			fflush(fp2);
		}
		else 
		{
			printf("回答错误！正确答案为：%s\n",title->answer);
			fprintf(fp2,"%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t%d\n",
			StudentID,major,grade,name,title->pronum,title->problem,
			answer,0.0,score,title->type);
			fflush(fp2);
		}
		title=title->next;
	}
	printf("回答完毕！按下任意键退出学生系统...\n");
	fclose(fp1);
	// 再次以 r+ 的形式打开，以供其他函数调用
	fp1=fopen("timu.txt","r+");
	fclose(fp2); 
	getchar();
	getchar();
	// 返回初始主菜单 
	PrintSystem();
	return;
}

// 多项填空 
void MultiAnswer()
{
	fclose(fp1);
	fclose(fp2);
	// 重新以 r+ 的方式打开题库文件
	fp1=fopen("timu.txt","r+");
	// 以 a+ 的形式打开学生作答文件
	fp2=fopen("stu.txt","a+");
	// 检查文件是否成功打开
	// 如果没有提示录入题目
	if (fp1==NULL)
	{
		printf("文件打开失败！请联系教师是否录入过题目。\n");
		getchar();
		getchar();
		StuFunction();
		return; 
	}
	unsigned int StudentID;
	char major[100];
	int grade;
	char name[100];
	char answer[1000];
	int type=1;
	float score=0.0;
	printf("请按照下面顺序依次输入信息：\n");
	printf("学号 专业 班级 姓名（以空格隔开）\n");
	scanf("%u%s%d%s",&StudentID,major,&grade,name);
	question *title;
	// 从文件中提取题库 
	title=RecordQue();
	if (title==NULL)
	{
		printf("题库为空！请联系教师录入题目。\n");
		printf("请按任意键返回学生主菜单...\n");
		// 关闭文件
		fclose(fp1);
		// 再次以 r+ 的形式打开，以供其他函数调用
		fp1=fopen("timu.txt","r+");
		getchar();
		getchar();
		// 返回学生功能菜单
		StuFunction();
		return;
	}
	printf("开始答题！\n");
	printf("请输入你的答案并按下回车提交。\n");
	printf("题号 题目\n");
	while (title!=NULL)
	{
		if (title->type!=1)
		{
			title=title->next;
			continue;
		}
		printf("%d %s\n",title->pronum,title->problem);
		scanf("%s",answer);
		fseek(fp2,0,SEEK_END);
		if (!strcmp(answer,title->answer))
		{
			printf("回答正确！\n");
			score+=title->score;
			fprintf(fp2,"%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t%d\n",
			StudentID,major,grade,name,title->pronum,title->problem,
			answer,title->score,score,title->type);
			fflush(fp2);
		}
		else 
		{
			printf("回答错误！正确答案为：%s\n",title->answer);
			fprintf(fp2,"%u\t%s\t%d\t%s\t%d\t%s\t%s\t%f\t%f\t%d\n",
			StudentID,major,grade,name,title->pronum,title->problem,
			answer,0.0,score,title->type);
			fflush(fp2);
		}
		title=title->next;
	}
	printf("回答完毕！按下任意键退出学生系统...\n");
	fclose(fp1);
	// 再次以 r+ 的形式打开，以供其他函数调用
	fp1=fopen("timu.txt","r+");
	fclose(fp2); 
	getchar();
	getchar();
	// 返回初始主菜单 
	PrintSystem();
	return;
}

