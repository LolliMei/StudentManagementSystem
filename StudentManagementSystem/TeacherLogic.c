#include "TeacherLogic.h"

extern User user;
extern redisContext* context;


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