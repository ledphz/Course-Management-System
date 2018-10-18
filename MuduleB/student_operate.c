#include<stdio.h>
#include"student_operate.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"class_operate.h"

extern Student_list * stu_head;
extern Course_list * cou_head;

int student_add_file()
{
	time_t t;
	FILE* log1;
	FILE *fp;
	Student_list *node, *node2;
	Student p;
	stu_course_list *stu_course_head, *lp, *lp1;
	char path[30];
	int i;
	printf("请输入文件路径：\n");
	scanf("%s", path);
	if((fp = fopen(path, "r")) == NULL)
	{
		printf("路径错误！\n");
		return 0;
	}
	log1 =fopen("log/log1.log","a");
	time(&t);
	fprintf(log1, "%s导入学生文件：%s\n", ctime(&t), path);
	fclose(log1);
	printf("hhh\n");
	node = find_student_list_end(stu_head);
	while(1)
	{
		fscanf(fp, "%d", &p.num);
		if(0 != feof(fp))
		{
			break;
		}
		log1 =fopen("log/log1.log","a");
		time(&t);
		fprintf(log1, "%s增加学生%d的记录\n", ctime(&t), p.num);
		fclose(log1);
		fscanf(fp, "%s%d%d", p.name, &p.course_num, &p.total_score);
		stu_course_head = (stu_course_list *)malloc(sizeof(stu_course_list));
		stu_course_head->next = NULL;
		p.course = stu_course_head;
		if(0 == p.course_num)
		{
			;
		}
		else
		{
			lp = stu_course_head;
			for(i = 0; i < p.course_num; ++i)
			{
				lp1 = (stu_course_list *)malloc(sizeof(stu_course_list));
				fscanf(fp, "%d", &lp1->course_num);
				lp1->next = NULL;
				lp->next = lp1;
				lp = lp->next;
			}
		}
		node2 = (Student_list *)malloc(sizeof(Student_list));
		node2->student = p;
		node2->next = NULL;
		node->next = node2;
		node = node->next;
	}
	fclose(fp);
	printf("导入成功！\n\n");
	return 0;
}

int student_add_keyboard()
{
	time_t t;
	FILE* log1;
	int i;
    Student_list *node, *node2;
	Student p;
	stu_course_list *stu_course_head, *lp, *lp1;
	node = find_student_list_end(stu_head);
	printf("请输入学号：");
	scanf("%d", &p.num);
	log1 =fopen("log/log1.log","a");
	time(&t);
	fprintf(log1, "%s增加学生%d的记录\n", ctime(&t), p.num);
	fclose(log1);
	printf("请输入姓名：");
	scanf("%s", p.name);
	printf("请输入已修课程：");
	scanf("%d", &p.course_num);
	printf("请输入总共学分：");
	scanf("%d", &p.total_score);
	stu_course_head = (stu_course_list *)malloc(sizeof(stu_course_list));
	stu_course_head->next = NULL;
	p.course = stu_course_head;
	if(0 == p.course_num)
	{
		;
	}
	else
	{
		lp = stu_course_head;
		for(i = 0; i < p.course_num; ++i)
		{
			lp1 = (stu_course_list *)malloc(sizeof(stu_course_list));
			printf("请输入第%d个已修课程的课程号：", i+1);
			scanf("%d", &lp1->course_num);
			lp1->next = NULL;
			lp->next = lp1;
			lp = lp->next;
		}
	}
	node2 = (Student_list *)malloc(sizeof(Student_list));
	node2->student = p;
	node2->next = NULL;
	node->next = node2;
	node = node->next;
	return 0;
}

int student_del()
{
	int num;
	Student_list *a;
	time_t t;
	FILE* log1;
    printf("输入要删除学生的学号：");
	scanf("%d", &num);
	a = find_student_list_num_before(stu_head, num);
	if(NULL == a)
	{
		printf("没有此学生!\n");
	}
	else
	{
		log1 =fopen("log/log1.log","a");
		time(&t);
		fprintf(log1, "%s删除学生%d的记录\n", ctime(&t), num);
		fclose(log1);
		del_stu_relation_cou(get_student_couse_list(a->next), num);
		a->next = a->next->next;
		printf("删除成功!\n");
	}
	return 0;
}

int student_revise_student_num()
{
	time_t t;
	FILE* log1;
	int num, new_num;
	Student_list* p1, *p2;
	printf("请输入原学号:");
	scanf("%d", &num);
	p1 = student_num_get_student(stu_head, num);
	if(NULL == p1)
	{
		printf("不存在该学生\n");
	}
	else
	{
		printf("请输入新学号:");
		scanf("%d", &new_num);
		p2 = student_num_get_student(stu_head, new_num);
		if(NULL != p2)
		{
			printf("已存在该学号\n");
		}
		else
		{
			re_stu_num(p1->student.course, num, new_num);
			p1->student.num = new_num;
			log1 =fopen("log/log1.log","a");
			time(&t);
			fprintf(log1, "%s修改学生%d学号改为%d\n", ctime(&t), num, new_num);
			fclose(log1);
			printf("修改成功!\n");
		}
	}
}

int student_revise_student_name()
{
	int num;
	char new_name[18];
	time_t t;
	FILE* log1;
	Student_list* p1;
	printf("请输入原学号:");
	scanf("%d", &num);
	p1 = student_num_get_student(stu_head, num);
	if(NULL == p1)
	{
		printf("不存在该学生\n");
	}
	else
	{
		printf("请输入新姓名:");
		scanf("%s", new_name);
		strcpy(p1->student.name, new_name);
		log1 =fopen("log/log1.log","a");
		time(&t);
		fprintf(log1, "%s修改学生%d姓名改为%s\n", ctime(&t), num, new_name);
		fclose(log1);
		printf("修改成功!\n");
	}
}

int revise_add_course()
{
	time_t t;
	FILE* log1;
	int s_num, c_num;
	Student_list * stu1;
	Course_list * cou1;
	printf("哪位学生要增加课程？请输入学号:");
	scanf("%d", &s_num);
	printf("输入要添加的课程号:");
	scanf("%d", &c_num);
	stu1 = student_num_get_student(stu_head, s_num);
	cou1 = course_num_get_course(cou_head, c_num);
	if(1 == course_if_be(stu1->student.course, c_num))
	{
		printf("该生已选修该课程！");
	}
	else
	{
		if(0 == course_increase_one(c_num)) /*增加课程人数*/
		{
			printf("人数已满，无法添加!\n");
		}
		else
		{
		c_list_add_s(cou1->course.student, s_num);/*增加课程的人员*/
		stu1->student.total_score += cou1->course.score;/*增加学生学分*/
		stu1->student.course_num += 1;/*增加学生所修课程数*/
		s_list_add_c(stu1->student.course, c_num);/*增加学生所修课程*/
		log1 =fopen("log/log1.log","a");
		time(&t);
		fprintf(log1, "%s修改学生%d修改课程%d，增加相互关联\n", ctime(&t), s_num, c_num);
		fclose(log1);
		printf("增加成功！\n");
		}
	}
	return 0;
}

int revise_del_course()
{
	time_t t;
	FILE* log1;
	int s_num, c_num;
	Student_list * stu1;
	Course_list * cou1;
	printf("哪位学生要删除课程？请输入学号:");
	scanf("%d", &s_num);
	printf("输入要删除的课程号:");
	scanf("%d", &c_num);
	stu1 = student_num_get_student(stu_head, s_num);
	cou1 = course_num_get_course(cou_head, c_num);
	if(0 == course_if_be(stu1->student.course, c_num))
	{
		printf("该生未选修该课程！\n");
	}
	else
	{
		course_reduce_one(c_num); /*减少课程人数*/
		c_list_del_s(cou1->course.student, s_num);/*减少课程的人员*/
		stu1->student.total_score -= cou1->course.score;/*减少学生学分*/
		stu1->student.course_num -= 1;/*增加学生所修课程数*/
		s_list_del_c(stu1->student.course, c_num);/*增加学生所修课程*/
		log1 =fopen("log/log1.log","a");
        time(&t);
        fprintf(log1, "%s修改学生%d修改课程%d，删除相互关联\n", ctime(&t), s_num, c_num);
        fclose(log1);
		printf("删除成功！\n");
	}
	return 0;
}

int student_see_all()
{
	Student_list *node;
	Student p;
	stu_course_list *stu_course_head, *lp;
	node = stu_head->next;
	printf("学号\t姓名\t已选课程\t已修学分\t\n");
	while(NULL != node)
	{
		p = node->student;
		printf("%d\t%s\t%d\t\t%d\t", p.num, p.name, p.course_num, p.total_score);
		printf("\n");
		node = node->next;
	}
	return 0;
}

int student_see_one()
{
	int num;
	Student_list* p1;
	Student p;
	stu_course_list* cou_list;
	printf("请输入要查看学生的学号:");
	scanf("%d", &num);
	p1 = student_num_get_student(stu_head, num);
	p = p1->student;
	printf("学号\t姓名\t已选课程\t已修学分\t\n");
	printf("%d\t%s\t%d\t%d\t\t\n", p.num, p.name, p.course_num, p.total_score);
	printf("已选课程:\n");
	if(0 == p.course_num)
	{
		printf("无\n");
	}
	else
	{
		cou_list = p.course->next;
		while(NULL != cou_list)
		{
			printf("%d\t", cou_list->course_num);
			cou_list = cou_list->next;
		}
		printf("\n");
	}
}

int student_save()
{
	time_t t;
    FILE* log1;
    FILE *fp;
	char path[30];
	Student_list *node;
	Student p;
	stu_course_list *stu_course_head, *lp;
	printf("请输入文件路径：\n");
	scanf("%s", path);
	if((fp = fopen(path, "w")) == NULL)
	{
		printf("路径错误！\n");
		return 0;
	}
	log1 =fopen("log/log1.log","a");
	time(&t);
	fprintf(log1, "%s保存学生文件：%s\n", ctime(&t), path);
	fclose(log1);
	node = stu_head->next;
	while(NULL != node)
	{
		p = node->student;
		fprintf(fp,"%d %s %d %d\n", p.num, p.name, p.course_num, p.total_score);
		if(0 == p.course_num)
		{
			;
		}
		else
		{
			lp = p.course->next;
			while(NULL != lp->next)
			{
				fprintf(fp, "%d\t", lp->course_num);
				lp = lp->next;
			}
			fprintf(fp, "%d\t", lp->course_num);
		}
		fprintf(fp, "\n\n");
		node = node->next;
	}
	fclose(fp);
	printf("信息保存成功!\n");
	return 0;
}




Student_list* find_student_list_end(Student_list* stu_head)
{
    Student_list *p = stu_head;
    while(p->next != NULL)
    {   
        p = p->next;
    }   
    return p;
}

Student_list* find_student_list_num_before(Student_list* stu_head, int num)
{
    Student_list* a = stu_head;
    Student_list* b = stu_head->next;
    for(; b->next != NULL; a = a->next, b = b->next)
    {   
        if(b->student.num == num)
		{
            return a;
        }
    }   
    if(b->student.num == num)
    {
    	return a;
    }
    return NULL;
}

stu_course_list* get_student_couse_list(Student_list *p)
{
	return p->student.course;
}

void del_stu_relation_cou(stu_course_list* p, int num)
{
	Course_list * cou1;
	stu_course_list* a = p->next;
	while(NULL != a)
	{
		course_reduce_one(a->course_num);/*课程已修人数自减*/
		cou1 = course_num_get_course(cou_head, a->course_num);/*根据课程号获取课程*/
		c_list_del_s(cou1->course.student, num);/*删除课程拥有的某个学生*/
		a = a->next;
	}
}

void course_reduce_one(int course_num)
{
	Course_list * a = cou_head;
	while(NULL != a)
	{
		if(course_num == a->course.num)
		{
			a->course.people--;
		}
		a = a->next;
	}
}

int course_increase_one(int course_num)
{
	Course_list * a = cou_head;
	while(NULL != a)
	{
		if(course_num == a->course.num)
		{
			if(a->course.people == a->course.people_max)
			{
				return 0;
			}
			else
			{
				a->course.people++;
			}
		}
		a = a->next;
	}
	return 1;
}

Student_list * student_num_get_student(Student_list * stu_head, int num)
{
	Student_list * p =stu_head->next;
	while(NULL != p)
	{
		if(num == p->student.num)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void s_list_add_c(stu_course_list * a, int c_num)
{
	stu_course_list *insert;
	insert=(stu_course_list *)malloc(sizeof(stu_course_list));
	insert->course_num = c_num;
	insert->next = a->next;
	a->next = insert;
}

void s_list_del_c(stu_course_list * p, int c_num)
{
	stu_course_list *a, *b;
	a = p;
	b = p->next;
	for(; NULL != b; a = a->next, b = b->next)
	{
		if(c_num == b->course_num)
		{
			a->next = b->next;
		}
	}
}

int course_if_be(stu_course_list * a, int c_num)
{
	while(NULL != a)
	{
		if(c_num == a->course_num)
		{
			return 1;
		}
		a = a->next;
	}
	return 0;
}

void re_stu_num(stu_course_list* stu_cou_list, int s_num, int new_s_num)
{
	stu_course_list* a = stu_cou_list->next;
	while(NULL != a)
	{
		re_course_list_student_num_to_new(find_cou_list(a->course_num), s_num, new_s_num);
		a = a->next;
	}
}

stu_course_list* find_stu_list(int s_num)
{
    Student_list* p = stu_head;
    while(NULL != p)
    {   
        if(s_num == p->student.num)
        {   
            return p->student.course;
        }
        p = p->next;
    }
    return NULL;
}

int re_student_list_course_num_to_new(stu_course_list* p, int c_num, int new_c_num)
{
    stu_course_list *a = p;
    while(NULL != a)
    {   
        if(a->course_num == c_num)
        {
            a->course_num = new_c_num;
        }
        a = a->next;
    }   
    return 0;
}

