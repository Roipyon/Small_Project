#include <stdio.h>
#include <stdlib.h>
#include "users.h"
#include "teacher.h"
#include "student.h"
#include <string.h>

#define USERNAME "Admin"
#define PASSWORD 123456

//输出系统界面 
void PrintSystem(void)
{
	// 记录用户输入的数字 
	int flag;
	printf("╔════════════════════════════════╗\n");
	printf("║	英语单词填空练习系统	 ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║	欢迎使用英语练习系统！ 	 ║\n");
	printf("║			 	 ║\n");
	printf("║	  请选择你的身份	 ║\n");
	printf("║	 ┌──────────────┐	 ║\n");
	printf("║	 │  1.教师      │	 ║\n");
	printf("║	 │  2.学生      │	 ║\n");
	printf("║	 │  3.退出系统  │	 ║\n");
	printf("║	 └──────────────┘	 ║\n");
	printf("╠════════════════════════════════╣\n");
	printf("║    输入数字选择，按下回车确认  ║\n");
	printf("╚════════════════════════════════╝\n");
	scanf("%d",&flag);
	if (flag==1)
	{
		// TeaFunction();
		int attempts=5;
		while (attempts)
		{
			char username[100];
			int password;
			printf("╔════════════════════════════════╗\n");
			printf("║	   用户登录系统		 ║\n");
			printf("╠════════════════════════════════╣\n");
			printf("║	   请输入用户名	 	 ║\n");
			scanf("%s",username);
			printf("╚════════════════════════════════╝\n");
			printf("╔════════════════════════════════╗\n");
			printf("║	   用户登录系统		 ║\n");
			printf("╠════════════════════════════════╣\n");
			printf("║	    请输入密码		 ║\n");
			scanf("%d",&password);
			printf("╚════════════════════════════════╝\n");
			// 对比用户名和密码，两者均符合才进入系统 
			if (!strcmp(username,USERNAME) && !(password-PASSWORD))
			{
				// 调用教师权限函数 
				TeaFunction();
			}
			else 
			{
				attempts--;
				printf("╔════════════════════════════════╗\n");
				printf("║	 账号或密码错误！	 ║\n");
				printf("║	 你现在还有%d次机会。	 ║\n",attempts);
				printf("╚════════════════════════════════╝\n");
			} 
		}
		printf("╔════════════════════════════════╗\n");
		printf("║	登录失败次数过多！	 ║\n");
		printf("║     请按下任意键退出程序...    ║\n");
		printf("╚════════════════════════════════╝\n");
		getchar();
		getchar();
		return;
	}
	else if (flag==2)
	{
		// 调用学生权限函数 
		StuFunction();
	}
	else if (flag==3)
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    英语练习系统已退出。  	 ║\n");
		printf("║    请输入任意键退出程序...     ║\n");
		printf("╚════════════════════════════════╝\n");
		getchar();
		getchar();
		return;
	}
	else 
	{
		printf("╔════════════════════════════════╗\n");
		printf("║    	 请输入有效数字！  	 ║\n");
		printf("╚════════════════════════════════╝\n");
		printf("\n");
		// 再次调用 PrintSystem 函数输出系统界面 
		PrintSystem();
		return;
	} 
}

	
