#include<stdio.h>
#include<stdlib.h>
#include"student_operate.h"
#include"class_operate.h"
#include"menu.h"

void menu_main()
{
	int input;
	while(1)
	{
		system("clear");
		printf("1.学生信息\n");
		printf("2.课程信息\n");
		printf("3.退出程序\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				menu_student();
				break;
			case 2:
				menu_class();
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_student()
{
	int input;
	while(1)
	{
		system("clear");
		printf("1.增加\n");
		printf("2.删除\n");
		printf("3.修改\n");
		printf("4.查看\n");
		printf("5.保存\n");
		printf("6.返回上一页\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		system("clear");
		switch(input)
		{
			case 1:
				if(1 == menu_student_add())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == menu_student_del())
				{
					return 1;
				}
				break;
			case 3:
				if(1 == menu_student_revise())
				{
					return 1;
				}
				break;
			case 4:
				if(1 == menu_student_see())
				{
					return 1;
				}
				break;
			case 5:
				if(1 == menu_student_save())
				{
					return 1;
				}
				break;
			case 6:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_student_add()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.文件导入\n");
		printf("2.键盘导入\n");
		printf("3.返回上一页\n");
		printf("4.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == student_add_file())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == student_add_keyboard())
				{
					return 1;
				}
				break;
			case 3:
				return 0;
			case 4:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_student_del()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.删除学生信息\n");
		printf("2.返回上一页\n");
		printf("3.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == student_del())
				{
					return 1;
				}
				break;
			case 2:
				return 0;
			case 3:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_student_revise()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.修改学生信息\n");
		printf("2.增加学生所选课程\n");
		printf("3.删除学生所选课程\n");
		printf("4.返回上一页\n");
		printf("5.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == menu_student_revise_student())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == revise_add_course())
				{
					return 1;
				}
				break;
			case 3:
				if(1 == revise_del_course())
				{
					return 1;
				}
				break;
			case 4:
				return 0;
			case 5:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_student_revise_student()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.修改学号\n");
		printf("2.修改姓名\n");
		printf("3.返回上一页\n");
		printf("4.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == student_revise_student_num())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == student_revise_student_name())
				{
					return 1;
				}
				break;
			case 3:
				return 0;
			case 4:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_student_see()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.查看所有学生信息\n");
		printf("2.查看个人具体信息\n");
		printf("3.返回上一页\n");
		printf("4.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == student_see_all())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == student_see_one())
				{
					return 1;
				}
				break;
			case 3:
				return 0;
			case 4:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_student_save()
{
	int input;
	while(1)
	{
		system("clear");
		printf("1.保存修改\n");
		printf("2.返回上一页\n");
		printf("3.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == student_save())
				{
					return 1;
				}
				break;
			case 2:
				return 0;
			case 3:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_class()
{
	int input;
	while(1)
	{
		system("clear");
		printf("1.增加\n");
		printf("2.删除\n");
		printf("3.修改\n");
		printf("4.查看\n");
		printf("5.保存\n");
		printf("6.返回上一页\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		system("clear");
		switch(input)
		{
			case 1:
				if(1 == menu_class_add())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == menu_class_del())
				{
					return 1;
				}
				break;
			case 3:
				if(1 == menu_class_revise())
				{
					return 1;
				}
				break;
			case 4:
				if(1 == menu_class_see())
				{
					return 1;
				}
				break;
			case 5:
				if(1 == menu_class_save())
				{
					return 1;
				}
				break;
			case 6:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_class_add()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.文件导入\n");
		printf("2.键盘导入\n");
		printf("3.返回上一页\n");
		printf("4.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == class_add_file())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == class_add_keyboard())
				{
					return 1;
				}
				break;
			case 3:
				return 0;
			case 4:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_class_del()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.删除课程信息\n");
		printf("2.返回上一页\n");
		printf("3.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == class_del())
				{
					return 1;
				}
				break;
			case 2:
				return 0;
			case 3:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_class_revise()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.修改课程信息\n");
		printf("2.增加课程拥有学生\n");
		printf("3.删除课程拥有学生\n");
		printf("4.返回上一页\n");
		printf("5.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == menu_class_revise_class())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == revise_add_course())
				{
					return 1;
				}
				break;
			case 3:
				if(1 == revise_del_course())
				{
					return 1;
				}
				break;
			case 4:
				return 0;
			case 5:
				return 1;
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_class_revise_class()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.修改课程号\n");
		printf("2.修改课程名\n");
		printf("3.返回上一页\n");
		printf("4.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == class_revise_class_num())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == class_revise_class_name())
				{
					return 1;
				}
				break;
			case 3:
				return 0;
			case 4:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_class_see()
{
	int input;
	while(1)
	{
		printf("\n");
		printf("1.查看所有课程信息\n");
		printf("2.查看课程具体信息\n");
		printf("3.返回上一页\n");
		printf("4.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == class_see_all())
				{
					return 1;
				}
				break;
			case 2:
				if(1 == class_see_one())
				{
					return 1;
				}
				break;
			case 3:
				return 0;
			case 4:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}

int menu_class_save()
{
	int input;
	while(1)
	{
		system("clear");
		printf("1.保存修改并把临时日志添加进日志里\n");
		printf("2.返回上一页\n");
		printf("3.返回主菜单\n");
		printf("请输入相应选项:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				if(1 == class_save())
				{
					return 1;
				}
				break;
				break;
			case 2:
				return 0;
			case 3:
				return 1;
			default:
				printf("非法输入!\n");
				break;
		}
	}
}
