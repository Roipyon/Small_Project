#ifndef TEACHER_H
#define TEACHER_H

typedef struct student student;

void TeaFunction();

void TitleSystem();

void TitleRecord();

void TitleAdd();

void TitleDelete();
 
void ScoreSystem();

void ScoreFind(); 

void FindForName(student *wait_to_find);

void FindForGrade(student *wait_to_find);

void FindForMajor(student *wait_to_find);

void FindForIDRange(student *wait_to_find);

void ScoreCount();

void CountForGrade(student *wait_to_count);

void CountForMajor(student *wait_to_count);

void CountForIDRange(student *wait_to_count);

void ScoreSort();

void SortForScore(student *wait_to_sort);

void SortForGrade(student *wait_to_sort);

#endif
