#include "StudentLogic.h"
#include <stdlib.h>
#include <hiredis.h>
#include <string.h>
#include "Login.h"
#include "Query.h"

extern User user;
extern redisContext* context;
//����ѧ����Ϣ
void LoadStudentInfo(Student* stud)
{
	extern User user;
	redisReply* reply;
	redisContext* context = redisConnect("127.0.0.1", 6379);
	char* cmd;
	char prefix[100];
	char key[100];
	sprintf(prefix, "student:%s", user.username);
	cmd = ConstructGetCommand(strcat(key, "name"));
	reply = (redisReply*)redisCommand(context, cmd);
	strcpy(stud->name, reply->str);

	ConstructGetCommand(strcat(key, "sex"));
	reply = (redisReply*)redisCommand(context, cmd);
	strcpy(stud->sex, reply->str);

	ConstructGetCommand(strcat(key, "age"));
	reply = (redisReply*)redisCommand(context, cmd);
	strcpy(stud->age, reply->str);

	ConstructGetCommand(strcat(key, "birth"));
	reply = (redisReply*)redisCommand(context, cmd);
	strcpy(stud->birth, reply->str);

	free(reply);
	free(cmd);
}


void StudentProfile()
{

}

void StudentCourseToSelect()
{
}

void StudentCourseSelected()
{
}

void StudentScore()
{
}

void StudentChangePassword()
{
	//У��ԭ����
	char origin[20] = { 0 };
	printf("������ԭ����");
	scanf_s("%s", origin, 20);
	char* cmd = ConstructCommand("get login:student:%s", user.username);
	redisReply* reply = redisCommand(context, cmd);

	if (HandleReply(reply) && strcmp(origin, reply->str) == 0)
	{
		char newPassword1[20];
		char newPassword2[20];
		//����������
		printf("������������:\n");
		//ȷ��������
		printf("��ȷ��������:\n");
		//��������һ�£����������
		if (strcmp(newPassword1, newPassword2))
		{
			redisCommand(context, "set login:student:%s %s", user.username, newPassword1);
		}

	}
	printf("ҵ����ɣ����������!");
	getchar();
}

void StudentExit()
{
	user.verify = 0;
	memset(user.username,0,20);
	user.type = UNKNOWN;
}