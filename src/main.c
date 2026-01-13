#include <stdio.h>
#include <stdlib.h>
#include "users.h"
#include "var.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	fp1=fopen("timu.txt","a+"); 
	fp2=fopen("stu.txt","a+"); 
	fp3=fopen("sort1.txt","a+");
	fp4=fopen("sort2.txt","a+");
	if (fp1==NULL || fp2==NULL || fp3==NULL || fp4==NULL)
	{
		printf("文件打开失败！请检查文件是否存在或文件格式是否正确！\n");
		exit(0);			
	} 
	PrintSystem(); 
	return 0;
}
