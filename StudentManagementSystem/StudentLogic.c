#include "StudentLogic.h"
#include <stdlib.h>
#include <hiredis.h>
#include <string.h>
#include "Login.h"
#include "Query.h"

extern User user;
extern redisContext* context;
//加载学生信息
void LoadStudentInfo(Student* stud)
{
	extern User user;
	redisReply* reply;
	redisContext* context = redisConnect("127.0.0.1", 6379);
	reply = (redisReply*)redisCommand(context, "get student:%s:name",user.username);
	strcpy(stud->name, reply->str);

	reply = (redisReply*)redisCommand(context, "get student:%s:sex",user.username);
	strcpy(stud->sex, reply->str);

	reply = (redisReply*)redisCommand(context, "get student:%s:age",user.username);
	strcpy(stud->age, reply->str);


	reply = (redisReply*)redisCommand(context, "get student:%s:birth",user.username);
	strcpy(stud->birth, reply->str);

	reply = (redisReply*)redisCommand(context, "get student:%s:grade",user.username);
	stud->grade = atoi(reply->str);

	reply = (redisReply*)redisCommand(context, "get student:%s:majorcode",user.username);
	stud->majorcode = atoi(reply->str);

	reply = (redisReply*)redisCommand(context, "get major:code:%d",stud->majorcode);
	strcpy(stud->major, reply->str);

	free(reply);
}

//学生档案
void StudentProfile()
{
	Student stud;
	LoadStudentInfo(&stud);
	printf("个人基本信息:\n");
	printf("姓名:%s\n",stud.name);
	printf("性别:%s\n",stud.sex);
	printf("出生日期:%s\n", stud.birth);
	printf("学号:%s\n",user.username);
	printf("专业:%d级%s(专业代码%d)",stud.grade,stud.major,stud.majorcode);
	system("pause");
}

void StudentCourseToSelect()
{
	//查询开课班keys
	redisReply* reply = redisCommand(context,"keys next_course:*:name");

	//根据keys查询开课班名字
	for (size_t i = 0; i < reply->elements; i++)
	{
		printf("%s \n",reply->element[i]->str);
		redisReply* requestName = redisCommand(context, "get %s", reply->element[i]->str);
		printf("courseName:%s\n",requestName->str);
	}
}

void StudentCourseSelected()
{
}

void StudentScore()
{
}

void StudentChangePassword()
{
	//校验原密码
	char origin[20] = { 0 };
	printf("请输入原密码");
	scanf_s("%s", origin, 20);
	char* cmd = ConstructCommand("get login:student:%s", user.username);
	redisReply* reply = redisCommand(context, cmd);

	if (HandleReply(reply) && strcmp(origin, reply->str) == 0)
	{
		char newPassword1[20];
		char newPassword2[20];
		//输入新密码
		printf("请输入新密码:\n");
		//确认新密码
		printf("请确认新密码:\n");
		//两次输入一致，则更改密码
		if (strcmp(newPassword1, newPassword2))
		{
			redisCommand(context, "set login:student:%s %s", user.username, newPassword1);
		}

	}
	printf("业务完成，任意键返回!");
	getchar();
}

void StudentExit()
{
	user.verify = 0;
	memset(user.username,0,20);
	user.type = UNKNOWN;
}