#include "AdminLogic.h"

extern User user;
extern redisContext* context;


//����Ա�޸�����
void AdminChangePassword()
{
	//У��ԭ����
	char origin[20] = { 0 };
	printf("������ԭ����");
	scanf_s("%s", origin, 20);
	char* cmd = ConstructCommand("get login:admin:%s", user.username);
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
			redisCommand(context, "set login:admin:%s %s", user.username, newPassword1);
		}

	}
	printf("ҵ����ɣ����������!");
	getchar();
}

//����Ա�˳�
void AdminExit()
{
	user.verify = 0;
	memset(user.username,0,20);
	user.type = UNKNOWN;
}