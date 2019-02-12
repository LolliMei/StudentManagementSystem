#include "UI.h"
#include <assert.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Login.h"
#include "define.h"
#include "AdminLogic.h"
#include "StudentLogic.h"
#include "TeacherLogic.h"

#define STUDENT_CONST 1
#define TEACHER_CONST 2
#define ADMIN_CONST 3

#define STUDENT_EXIT 0
#define STUDENT_PROFILE 1
#define STUDENT_COURSE_TO_SELECT 2
#define STUDENT_COURSE_SELECTED 3
#define STUDENT_SCORE 4
#define STUDENT_CHANGE_PW 5

#define TEACHER_EXIT 0
#define TEACHER_PROFILE 2
#define TEACHER_UPLOAD_SCORE 4
#define TEACHER_MANAGER_COURSE 6
#define TEACHER_VIEW_STUDENT 8
#define TEACHER_APPLY_COURSE 10
#define TEACHER_CHANGE_PW 12

#define ADMIN_EXIT 0
#define ADMIN_USER_PERMISSION 3
#define ADMIN_MANAGE_STUDENT 6
#define ADMIN_MANAGE_TEACHER 9
#define ADMIN_MANAGE_COURSE 12
#define ADMIN_ALLOW_COURSE 15
#define ADMIN_CHANGE_PW 18


extern User user;

//划线函数
static void DrawLine(int width)
{
	for (size_t i = 0; i < width; i++)
	{
		printf("*");
	}
	printf("\n");
}

//登录界面
int LoginPage()
{
	system("cls");
	DrawLine(40);
	printf("1、学生入口\n");
	printf("2、教师入口\n");
	printf("3、管理员入口\n");
	DrawLine(40);
	return getch() - 48;
}

//学生界面
int StudentInterface()
{
	system("cls");
	DrawLine(40);
	printf("1、查看个人信息\n");
	printf("2、查看备选课程\n");
	printf("3、查看已选课程\n");
	printf("4、查看成绩\n");
	printf("5、更改密码\n");
	printf("0、退出系统\n");
	DrawLine(40);
	return getch() - 48;
}

//教师界面
int TeacherInterface()
{
	DrawLine(40);
	printf("1、查看个人信息\n");
	printf("2、录入成绩\n");
	printf("3、管理开课班\n");
	printf("4、查看学生信息\n");
	printf("5、提交开课申请\n");
	printf("6、更改密码\n");
	printf("0、退出系统\n");
	DrawLine(40);
	return getch() - 48;
}

//管理员界面
int AdminInterface()
{
	DrawLine(40);
	printf("1、管理用户权限\n");
	printf("2、管理学生信息\n");
	printf("3、管理教师信息\n");
	printf("4、管理开课班\n");
	printf("5、批准开课信息\n");
	printf("6、更改密码\n");
	DrawLine(40);
	return getch() - 48;
}

//学生逻辑
void StudentLogicHandler()
{
	while (user.verify == 1)
	{
		/* code */

		switch (StudentInterface() * STUDENT_CONST)
		{
		case STUDENT_PROFILE:
			/* code */
			break;
		case STUDENT_COURSE_TO_SELECT:
			/* code */
			break;
		case STUDENT_COURSE_SELECTED:
			/* code */
			break;
		case STUDENT_SCORE:
			/* code */
			break;
		case STUDENT_CHANGE_PW:
			StudentChangePassword();
			break;
		case STUDENT_EXIT:
			StudentExit();
			break;
		default:
			break;
		}
	}
}

//教师逻辑
void TeacherLogicHandler()
{
	while (user.verify == 1)
	{

		switch (TeacherInterface() * TEACHER_CONST)
		{
		case TEACHER_PROFILE:
			/* code */
			break;
		case TEACHER_UPLOAD_SCORE:
			/* code */
			break;
		case TEACHER_MANAGER_COURSE:
			/* code */
			break;

		case TEACHER_VIEW_STUDENT:
			/* code */
			break;
		case TEACHER_APPLY_COURSE:
			/* code */
			break;
		case TEACHER_CHANGE_PW:
			/* code */
			TeacherChangePassword();
			break;
		case TEACHER_EXIT:
			/* code */
			TeacherExit();
			break;
		default:
			break;
		}
	}
}

//管理员逻辑
void AdminLogicHandler()
{
	while (user.verify == 1)
	{
		switch (AdminInterface() * ADMIN_CONST)
		{
		case ADMIN_CONST:
			/* code */
			break;
		case ADMIN_MANAGE_STUDENT:
			break;
		case ADMIN_MANAGE_TEACHER:
			break;

		case ADMIN_MANAGE_COURSE:
			break;

		case ADMIN_ALLOW_COURSE:
			break;

		case ADMIN_CHANGE_PW:
			AdminChangePassword();
			break;

		case ADMIN_EXIT:
			AdminExit();
			break;
		default:
			break;
		}
	}
}
