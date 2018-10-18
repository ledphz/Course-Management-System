#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"student_operate.h"
#include"class_operate.h"

Student_list * stu_head = NULL;
Course_list * cou_head = NULL;

int main()
{
	remove("log/log1.log");
	stu_head = (Student_list *)malloc(sizeof(Student_list));
	stu_head->next = NULL;
	cou_head = (Course_list *)malloc(sizeof(Course_list));
	cou_head->next = NULL;
	menu_main();
	return 0;
}
