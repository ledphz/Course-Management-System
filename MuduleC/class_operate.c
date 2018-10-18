#include<stdio.h>
#include"class_operate.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"student_operate.h"

extern Student_list * stu_head;
extern Course_list * cou_head;

int class_add_file()
{
	time_t t;
    FILE* log1;
	FILE *fp;
    Course_list *node, *node2;
    Course p;
    course_stu_list * course_stu_head, *lp, *lp1;
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
	fprintf(log1, "%s导入课程文件：%s\n", ctime(&t), path);
	fclose(log1);
    node = find_course_list_end(cou_head);
    while(1)
    {   
        fscanf(fp, "%d", &p.num);
        if(0 != feof(fp))
        {
            break;
        }
		log1 =fopen("log/log1.log","a");
        time(&t);
        fprintf(log1, "%s增加课程%d的记录\n", ctime(&t), p.num);
        fclose(log1);
        fscanf(fp, "%s%s%d%d%d%d", p.name, p.type, &p.time, &p.score, &p.people, &p.people_max);
        course_stu_head = (course_stu_list *)malloc(sizeof(course_stu_list));
        course_stu_head->next = NULL;
        p.student = course_stu_head;
        if(0 == p.people)
        {
            ;
        }
		else
        {
            lp = course_stu_head;
            for(i = 0; i < p.people; ++i)
            {
                lp1 = (course_stu_list *)malloc(sizeof(course_stu_list));
                fscanf(fp, "%d", &lp1->student_num);
                lp1->next = NULL;
                lp->next = lp1;
                lp = lp->next;
            }
        }
        node2 = (Course_list *)malloc(sizeof(Course_list));
        node2->course = p;
        node2->next = NULL;
        node->next = node2;
        node = node->next;
    }
    fclose(fp);
    printf("导入成功！\n\n");
    return 0;

}

int class_add_keyboard()
{
	time_t t;
	FILE* log1;
	int i;
    Course_list *node, *node2;
    Course p;
    course_stu_list *course_stu_head, *lp, *lp1;
    node = find_course_list_end(cou_head);
    printf("请输入课程号：");
    scanf("%d", &p.num);
	log1 =fopen("log/log1.log","a");
    time(&t);
    fprintf(log1, "%s增加课程%d的记录\n", ctime(&t), p.num);
    fclose(log1);
    printf("请输入课程名：");
    scanf("%s", p.name);
    printf("请输入课程类型：");
    scanf("%s", p.type);
    printf("请输入学时：");
    scanf("%d", &p.time);
    printf("请输入课程学分：");
    scanf("%d", &p.score);
    printf("请输入已修人数：");
    scanf("%d", &p.people);
    printf("请输入人数上限：");
    scanf("%d", &p.people_max);
    course_stu_head = (course_stu_list *)malloc(sizeof(course_stu_list));
    course_stu_head->next = NULL;
    p.student = course_stu_head;
    if(0 == p.people)
    {
        ;
    }
    else
    {
        lp = course_stu_head;
        for(i = 0; i < p.people; ++i)
        {
            lp1 = (course_stu_list *)malloc(sizeof(course_stu_list));
            printf("请输入第%d个已修此课程学生的学号：", i+1);
            scanf("%d", &lp1->student_num);
            lp1->next = NULL;
            lp->next = lp1;
            lp = lp->next;
        }
    }
    node2 = (Course_list *)malloc(sizeof(Course_list));
    node2->course = p;
    node2->next = NULL;
    node->next = node2;
    node = node->next;
    return 0;

}

int class_del()
{
	time_t t;
    FILE* log1;
	int num;
    Course_list *a;
    printf("输入要删除课程的课程号：");
    scanf("%d", &num);
    a = find_course_list_num_before(cou_head, num);
    if(NULL == a)
    {
        printf("没有此课程!\n");
    }
    else
    {
        del_cou_relation_stu(get_couse_student_list(a->next), num);
        a->next = a->next->next;
		log1 =fopen("log/log1.log","a");
        time(&t);
        fprintf(log1, "%s删除课程%d的记录\n", ctime(&t), num);
        fclose(log1);
        printf("删除成功!\n");
    }
    return 0;
}

int class_revise_class_num()
{
	time_t t;
    FILE* log1;
	int num, new_num;
    Course_list* p1, *p2;
    printf("请输入原课程号:");
    scanf("%d", &num);
    p1 = course_num_get_course(cou_head, num);
    if(NULL == p1)
    {
        printf("不存在该课程\n");
    }
    else
    {
        printf("请输入新课程号:");
        scanf("%d", &new_num);
        p2 = course_num_get_course(cou_head, new_num);
        if(NULL != p2)
        {
            printf("已存在该课程号\n");
        }
        else
        {
            re_cou_num(p1->course.student, num, new_num);
            p1->course.num = new_num;
			log1 =fopen("log/log1.log","a");
            time(&t);
            fprintf(log1, "%s修改课程%d课程号改为%d\n", ctime(&t), num, new_num);
            fclose(log1);
            printf("修改成功!\n");
        }
    }

}

int class_revise_class_name()
{
	time_t t;
    FILE* log1;
	int num;
    char new_name[18];
    Course_list* p1;
    printf("请输入原课程号:");
    scanf("%d", &num);
    p1 = course_num_get_course(cou_head, num);
    if(NULL == p1)
    {
        printf("不存在该课程\n");
    }
    else
    {
        printf("请输入新课程名:");
        scanf("%s", new_name);
        strcpy(p1->course.name, new_name);
        log1 =fopen("log/log1.log","a");
        time(&t);
        fprintf(log1, "%s修改课程%d课程名改为%s\n", ctime(&t), num, new_name);
        fclose(log1);
		printf("修改成功!\n");
    }

}

int class_see_all()
{
	Course_list *node;
    Course p;
    course_stu_list *course_stu_head, *lp;
    node = cou_head->next;
    printf("课程号\t课程名\t课程性质\t学时\t学分\t已修人数\t人数上限\t\n");
    while(NULL != node)
    {
        p = node->course;
        printf("%d\t%s\t%s\t\t%d\t%d\t%d\t\t%d\t", p.num,  p.name, p.type, p.time, p.score, p.people, p.people_max);
        printf("\n");
        node = node->next;
    }
	return 0;
}

int class_see_one()
{
	int num;
	Course_list* p1;
	Course p;
	course_stu_list* stu_list;
    printf("请输入要查看课程的课程号:");
    scanf("%d", &num);
    p1 = course_num_get_course(cou_head, num);
    p = p1->course;
    printf("课程号\t课程名\t课程性质\t学时\t学分\t已修人数\t人数上限\t\n");
    printf("%d\t%s\t%s\t\t%d\t%d\t%d\t\t%d\t\n", p.num, p.name, p.type, p.time,     p.score, p.people, p.people_max);
	printf("选此课的学生:\n");
    if(0 == p.people)
    {   
        printf("无\n");
    }   
    else
    {   
        stu_list = p.student->next;
        while(NULL != stu_list)
        {
            printf("%d\t", stu_list->student_num);
            stu_list = stu_list->next;
        }
        printf("\n");
    }

}

int class_save()
{
	time_t t;
	char ch;
	FILE* log2;
	FILE* log = fopen("log/log.log", "a");
	FILE* log1 = fopen("log/log1.log", "r");
	FILE *fp;
    char path[30];
    Course_list *node;
    Course p;
    course_stu_list *course_stu_head, *lp;
    printf("请输入文件路径：\n");
    scanf("%s", path);
    if((fp = fopen(path, "w")) == NULL)
    {
        printf("路径错误！\n");
        return 0;
    }
	log2 =fopen("log/log1.log","a");
    time(&t);
    fprintf(log2, "%s更新日志文件，并保存课程文件：%s\n\n\n", ctime(&t), path);
    fclose(log2);
    node = cou_head->next;
    while(NULL != node)
    {
        p = node->course;
        fprintf(fp,"%d %s %s %d %d %d %d\n", p.num, p.name, p.type, p.time, p.score, p.people, p.people_max);
        if(0 == p.people)
        {
            ;
        }
        else
        {
            lp = p.student->next;
            while(NULL != lp->next)
            {
                fprintf(fp, "%d\t", lp->student_num);
                lp = lp->next;
            }
            fprintf(fp, "%d\t", lp->student_num);
        }
        fprintf(fp, "\n\n");
        node = node->next;
    }
    fclose(fp);
	while(EOF != (ch=fgetc(log1)))
	{
		fputc(ch, log);
	}
	fclose(log);
	fclose(log1);
    printf("信息保存成功!\n");
    return 0;

}




Course_list* find_course_list_end(Course_list* cou_head)
{
    Course_list *p = cou_head;
    while(p->next != NULL)
    {   
        p = p->next;
    }   
    return p;

}

Course_list* find_course_list_num_before(Course_list* cou_head, int num)
{
    Course_list *a = cou_head;
    Course_list *b = cou_head->next;
    for(; b->next != NULL; a = a->next, b = b->next)
    {   
        if(b->course.num == num)
        {
            return a;
        }
    }   
    if(b->course.num == num)
    {
        return a;
    }
    return NULL;

}

course_stu_list* get_couse_student_list(Course_list *p)
{
    return p->course.student;
}

void del_cou_relation_stu(course_stu_list* p, int num)
{
	Student_list * stu1;
    course_stu_list* a = p->next;
	int c_course;
	c_course = get_c_course(num);
    while(NULL != a)
    {
        student_reduce_one(a->student_num);/*学生已修课程数自减*/
        stu1 = student_num_get_student(stu_head, a->student_num);/*根据学号获取学生*/
        stu1->student.total_score -= c_course;/*学生减少相应学分*/
		s_list_del_c(stu1->student.course, num);/*删除学生已拥有的某个课程*/
        a = a->next;
    }
}


void c_list_add_s(course_stu_list * a, int s_num)
{
	course_stu_list *insert;
    insert=(course_stu_list *)malloc(sizeof(course_stu_list));
    insert->student_num = s_num;
    insert->next = a->next;
    a->next = insert;
}

void c_list_del_s(course_stu_list * p, int s_num)
{
    course_stu_list *a, *b; 
    a = p;
    b = p->next;
    for(; NULL != b; a = a->next, b = b->next)
    {
        if(s_num == b->student_num)
        {
            a->next = b->next;
        }   
    }   
}

int get_c_course(int num)
{
	Course_list * p = cou_head;
	while(NULL != p)
	{
		if(num == p->course.num)
		{
			return p->course.score;
		}
		p = p->next;
	}
}

Course_list * course_num_get_course(Course_list * cou_head, int num)
{
    Course_list * p =cou_head->next;
    while(NULL != p)
    {   
        if(num == p->course.num)
        {
            return p;
        }
        p = p->next;
    }   
    return NULL;
}

void student_reduce_one(int student_num)
{
    Student_list * a = stu_head;
    while(NULL != a)
    {   
        if(student_num == a->student.num)
        {
            a->student.course_num--;
        }
        a = a->next;
    }   
}

void re_cou_num(course_stu_list* cou_stu_list, int c_num, int new_c_num)
{
	course_stu_list* a = cou_stu_list->next;
    while(NULL != a)
    {   
        re_student_list_course_num_to_new(find_stu_list(a->student_num), c_num, new_c_num);
        a = a->next;
    }
}

course_stu_list* find_cou_list(int c_num)
{
	Course_list* p = cou_head;
	while(NULL != p)
	{
		if(c_num == p->course.num)
		{
			return p->course.student;
		}
		p = p->next;
	}
	return NULL;
}

int re_course_list_student_num_to_new(course_stu_list* p, int s_num, int new_s_num)
{
	course_stu_list *a = p;
	while(NULL != a)
	{
		if(a->student_num == s_num)
		{
			a->student_num = new_s_num;
		}
		a = a->next;
	}
	return 0;
}
