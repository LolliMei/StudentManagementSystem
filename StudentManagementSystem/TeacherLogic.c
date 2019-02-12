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

//教师档案 //TODO:: 增加修改功能
void TeacherProfile()
{
	Teacher tech;
	LoadStudentInfo(&tech);
	printf("个人基本信息:\n");
	printf("姓名:%s\n",tech.name);
	printf("性别:%s\n",tech.sex);
	printf("出生日期:%s\n", tech.birth);
	printf("工号:%s\n",user.username);
	printf("职称:%s %s(专业代码%d)",tech.major,tech.level,tech.majorcode);
	system("pause");
}

void TeacherChangePassword()
{
	//校验原密码
	char origin[20] = { 0 };
	printf("请输入原密码");
	scanf_s("%s", origin, 20);
	char* cmd = ConstructCommand("get login:teacher:%s", user.username);
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
			redisCommand(context, "set login:teacher:%s %s", user.username, newPassword1);
		}

	}
	printf("业务完成，任意键返回!");
	getchar();
}

void TeacherExit()
{
	user.verify = 0;
	memset(user.username,0,20);
	user.type = UNKNOWN;
}