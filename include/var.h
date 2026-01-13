#ifndef VAR_H
#define VAR_H

// 学生 
typedef struct student
{ 
	// 存放学号 
	unsigned int StudentID;
	// 存放专业
	char major[1000];
	// 存放班级号 
	int grade;
	// 存放姓名
	char name[100];
	// 存放题号
	int pronum;
	// 存放题目 
	char problem[1000];
	// 存放答案
	char answer[100];
	// 存放每道题得分
	float score; 
	// 存放总分
	float total_score;
	// 答题类型
	int type; // 0表示单填，1表示多填
	// 存放下一个学生结构体的指针
	struct student * next; 
} student;

// 题库 
typedef struct question
{
	// 存放题号
	int pronum;
	// 存放题目 
	char problem[1000];
	// 存放答案
	char answer[100];
	// 存放得分
	float score; 
	// 存放题目类型
	// 0表示单填，1表示多填
	int type;
	// 存放下一道题的指针
	struct question * next; 
} question;


// 拓展文件指针 
extern FILE *fp1,*fp2,*fp3,*fp4;

// 声明全局变量
extern int n,n0,n1; 

// 声明结构体创建函数 

student *RecordStu();

student *RecordScore();

student *RecordScore_Single();

student *RecordScore_Mutiple();

question *creatque();

question *RecordQue();

#endif
