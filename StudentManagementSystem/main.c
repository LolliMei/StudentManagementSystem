#include "hiredis.h"
#define NO_QFORKIMPL
#include "win32fixes.h"
#include <stdbool.h>
#include "UI.h"
#include <stdlib.h>
#include <stdio.h>
#include "Login.h"
#include "define.h"

redisContext* context;
redisReply* reply;
User user;



void InitConnection()
{
	context = redisConnect("127.0.0.1", 6379);	
}
int main()
{
	InitConnection();
	//Test Fields




	//
	system("pause");

	//Ö÷Âß¼­
	while (true)
	{	
		switch (Login())
		{
			case STUDENT:
				StudentLogicHandler();
			break;
			case TEACHER:
				TeacherLogicHandler();
			break;
			case ADMIN:
				AdminLogicHandler();
			break;
			case UNKNOWN:
				
			break;
			default:
				break;
		}

	}
	return 0;
}
