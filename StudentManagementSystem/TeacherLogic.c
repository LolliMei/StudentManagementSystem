#include "TeacherLogic.h"

extern User user;
extern redisContext* context;

void LoadTeacherInfo(Teacher* tech)
{
	extern User user;
	redisReply* reply;
	redisContext* context = redisConnect("127.0.0.1", 6379);
	reply = (redisReply*)redisCommand(context, "get teacher:%s:name",user.username);
	strcpy(tech->name, reply->str);

	reply = (redisReply*)redisCommand(context, "get teacher:%s:sex",user.username);
	strcpy(tech->sex, reply->str);

	reply = (redisReply*)redisCommand(context, "get teacher:%s:age",user.username);
	strcpy(tech->age, reply->str);


	reply = (redisReply*)redisCommand(context, "get teacher:%s:birth",user.username);
	strcpy(tech->birth, reply->str);

	reply = (redisReply*)redisCommand(context, "get teacher:%s:exp",user.username);
	tech->exp = atoi(reply->str);

	reply = (redisReply*)redisCommand(context, "get teacher:%s:majorcode",user.username);
	tech->majorcode = atoi(reply->str);

	reply = (redisReply*)redisCommand(context, "get major:code:%d",tech->majorcode);
	strcpy(tech->major, reply->str);

	free(reply);
}

//��ʦ���� //TODO:: �����޸Ĺ���
void TeacherProfile()
{
	Teacher tech;
	LoadStudentInfo(&tech);
	printf("���˻�����Ϣ:\n");
	printf("����:%s\n",tech.name);
	printf("�Ա�:%s\n",tech.sex);
	printf("��������:%s\n", tech.birth);
	printf("����:%s\n",user.username);
	printf("ְ��:%s %s(רҵ����%d)",tech.major,tech.level,tech.majorcode);
	system("pause");
}

void TeacherChangePassword()
{
	//У��ԭ����
	char origin[20] = { 0 };
	printf("������ԭ����");
	scanf_s("%s", origin, 20);
	char* cmd = ConstructCommand("get login:teacher:%s", user.username);
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
			redisCommand(context, "set login:teacher:%s %s", user.username, newPassword1);
		}

	}
	printf("ҵ����ɣ����������!");
	getchar();
}

void TeacherExit()
{
	user.verify = 0;
	memset(user.username,0,20);
	user.type = UNKNOWN;
}