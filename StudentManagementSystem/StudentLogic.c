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

//ѧ������ //TODO:: �����޸Ĺ���
void StudentProfile()
{
	Student stud;
	LoadStudentInfo(&stud);
	printf("���˻�����Ϣ:\n");
	printf("����:%s\n",stud.name);
	printf("�Ա�:%s\n",stud.sex);
	printf("��������:%s\n", stud.birth);
	printf("ѧ��:%s\n",user.username);
	printf("רҵ:%d��%s(רҵ����%d)",stud.grade,stud.major,stud.majorcode);
	system("pause");
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