#ifndef CLASS_OPERATION_H
#define CLASS_OPERATION_H

typedef struct course_stu_list
{
    int student_num;
    struct course_stu_list *next;
}course_stu_list;

typedef struct cou 
{
    int num;
    char name[18];
    char type[18];
    int time;
    int score;
    int people;
    int people_max;
    struct course_stu_list * student;
}Course;

typedef struct course_list
{
    struct cou course;
    struct course_list * next;
}Course_list;

int class_add_file();
int class_add_keyboard();
int class_del();
int class_revise_class_num();
int class_revise_class_name();
int class_see_all();
int class_see_one();
int class_save();

Course_list* find_course_list_end(Course_list* cou_head);
Course_list* find_course_list_num_before(Course_list* cou_head, int num);

course_stu_list* get_couse_student_list(Course_list *p);
void del_cou_relation_stu(course_stu_list* p, int num);
void c_list_add_s(course_stu_list * a, int s_num);
void c_list_del_s(course_stu_list * p, int s_num);
int get_c_course(int num);
Course_list * course_num_get_course(Course_list * cou_head, int num);
void student_reduce_one(int student_num);

void re_cou_num(course_stu_list* cou_stu_list, int c_num, int new_c_num);
course_stu_list* find_cou_list(int c_num);
int re_course_list_student_num_to_new(course_stu_list* p, int s_num, int new_s_num);

#endif
