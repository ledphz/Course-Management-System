#ifndef STUDENT_OPERATION_H
#define STUDENT_OPERATION_H

typedef struct stu_course_list
{
    int course_num;
    struct stu_course_list *next;
}stu_course_list;

typedef struct stu 
{
    int num;
    char name[18];
	int course_num;
    int total_score;
    struct stu_course_list *course; 
}Student;

typedef struct student_list
{
    struct stu student;
    struct student_list * next;
}Student_list;

int student_add_file();
int student_add_keyboard();
int student_del();
int student_revise_student_num();
int student_revise_student_name();
int revise_add_course();
int revise_del_course();
int student_see_all();
int student_see_one();
int student_save();

Student_list* find_student_list_end(Student_list* stu_head);
Student_list* find_student_list_num_before(Student_list* stu_head, int num);

stu_course_list* get_student_couse_list(Student_list *p);
void del_stu_relation_cou(stu_course_list* p, int num);
void course_reduce_one(int course_num);
int course_increase_one(int course_num);
Student_list* student_num_get_student(Student_list * stu_head, int num);
void s_list_add_c(stu_course_list * a, int c_num);
void s_list_del_c(stu_course_list * p, int c_num);
int course_if_be(stu_course_list * a, int c_num);

void re_stu_num(stu_course_list* stu_cou_list, int s_num, int new_s_num);
stu_course_list* find_stu_list(int s_num);
int re_student_list_course_num_to_new(stu_course_list* p, int c_num, int new_c_num);


#endif
