#include "Query.h"
#include <malloc.h>
#include <string.h>

//构建命令的基函数
char* ConstructCommand(const char* format,...)
{
	char* buffer=(char*)malloc(sizeof(char)*300);
	va_list ap;
	va_start(ap,format);
	vsprintf_s(buffer,300,format,ap);
	return buffer;
}

//构建获取命令
char* ConstructGetCommand(char* key)
{
	char* cmd=ConstructCommand("get %s",key);
	return cmd;
}

//构建设置命令
char* ConstructSetCommand(char* key)
{
	char* cmd=ConstructCommand("set %s",key);
	return cmd;
}

//构建删除命令
char* ConstructDelCommand(char* key)
{
	char* cmd=ConstructCommand("del %s",key);
	return cmd;
}

//处理reply返回值
bool HandleReply(redisReply* reply)
{
	if(reply->str==NULL)
	{
		return false;
	}
	return true;
}

redisReply* GetCommandReply(char* key)
{
	extern redisContext* context;
	char* cmd  = ConstructGetCommand(key);
	return (redisReply*)redisCommand(context, cmd);
}

redisReply* SetCommandReply(char* key)
{
	extern redisContext* context;
	char* cmd  = ConstructSetCommand(key);
	return (redisReply*)redisCommand(context, cmd);
	
}

redisReply* DelCommandReply(char* key)
{
	extern redisContext* context;
	char* cmd  = ConstructDelCommand(key);
	return (redisReply*)redisCommand(context, cmd);
}

redisReply* ChangePasswordCommand(int type, char* username)
{
	switch (type)
	{
		case STUDENT:
			
		break;
		case TEACHER:

		break;
		case ADMIN:

		break;
		default:
			break;
	}
}


