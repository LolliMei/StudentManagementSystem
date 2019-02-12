#include "Login.h"
#include "define.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "UI.h"

extern User user;

bool Verified=false;

//检查是否存在对应的账号
bool UserExists(int type, char* usr)
{
	extern redisContext* context;
	redisReply* reply;
	switch (type)
	{

		case STUDENT:
			reply = (redisReply*)redisCommand(context, "EXISTS login:student:%s", usr);
			return reply->type==REDIS_REPLY_INTEGER && reply->integer == 1 ? true : false;
			break;

		case TEACHER:
			reply = (redisReply*)redisCommand(context, "EXISTS login:student:%s", usr);
			return reply->type==REDIS_REPLY_INTEGER && reply->integer == 1 ? true : false;

			break;
		case ADMIN:
			reply = (redisReply*)redisCommand(context, "EXISTS login:student:%s", usr);
			return reply->type==REDIS_REPLY_INTEGER && reply->integer == 1 ? true : false;

			break;

		default:
			assert(0);
			break;
	}

}

//输入用户名
char* InputUsername(int type)
{
	char* usrname=malloc(sizeof(char)*20);
	//char usrname[20];
	printf("请输入用户名：\n");
	scanf_s("%s",usrname,20);
	if(UserExists(type,usrname))
	{
		return usrname;
	}
	return NULL;
}

//输入密码，返回密码字符串
char* InputPassword()
{
	char* pwd = malloc(sizeof(char) * 20);
	printf("请输入密码：");
	int index = 0;
	while (true)
	{
		char c = _getch();
		switch (c)
		{
			case ENTER:
				pwd[index] = '\0';
				return pwd;
				break;
			case BACKSPACE:
				printf("\b \b");
				index--;
				break;
			case STREND:
				break;
			default:
				if (index == 17)
				{
					printf("Password Over Length");
					system("pause");
					return NULL;
				}
				pwd[index] = c;
				index++;
				printf("*");
				break;
		}
	}
	return NULL;
}

//构建查询密码命令
char* ConstructVerifyCommand(char* username,int type)
{
	char* cmd;
	switch (type)
	{
		case STUDENT:
			cmd=ConstructCommand("get login:student:%s",username);
		break;
		case TEACHER:
			cmd=ConstructCommand("get login:teacher:%s",username);
		break;
		case ADMIN:
			cmd=ConstructCommand("get login:admin:%s",username);
		break;
		default:
			assert(0);
	}
	//printf("%s\n",cmd);
	return cmd;
}

//验证密码是否正确
bool VerifyPassword(int type,char* username,char* pwd)
{
	char* cmd=ConstructVerifyCommand(username,type);
	redisContext* context=redisConnect("127.0.0.1",6379);
	redisReply* reply=(redisReply*)redisCommand(context,cmd);
	free(cmd);
	if(!HandleReply(reply)) return false;
	return !strcmp(reply->str,pwd);
}

// 登录校检
int LoginVerify(int type)
{
	char* username;
	char* pwd;
	switch (type)
	{
		case STUDENT:
			 username=InputUsername(STUDENT);
			 pwd=InputPassword();
			if (VerifyPassword(STUDENT,username,pwd ))
			{
				user.verify = 1;
				strncpy(user.username,username,strlen(username));
				user.type = STUDENT;
				return STUDENT;
			}
			break;
		case TEACHER:
			 username=InputUsername(TEACHER);
			 pwd=InputPassword();
			if (VerifyPassword(TEACHER,username,pwd ))
			{
				user.verify = 1;
				strncpy(user.username,username,strlen(username));
				user.type = TEACHER;
				return TEACHER;
			}
			break;
			
		case ADMIN:
			 username=InputUsername(ADMIN);
			 pwd=InputPassword();
			if (VerifyPassword(ADMIN,username,pwd ))
			{
				user.verify = 1;
				strncpy(user.username,username,strlen(username));
				user.type = ADMIN;
				return ADMIN;
			}
			break;
		default:
			assert(0);
			break;
	}
	return 0;
}

int Login()
{
	while (!Verified)
	{
		const int type = LoginPage();

		switch (type)
		{
			case STUDENT:
				return LoginVerify(STUDENT);
		
				break;

			case TEACHER:
				return LoginVerify(TEACHER);
				break;

			case ADMIN:
				return LoginVerify(ADMIN);
				break;

			default:
				break;
		}
	}
	return 0;

}