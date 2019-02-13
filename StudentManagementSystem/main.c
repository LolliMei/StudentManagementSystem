#include "hiredis.h"
#define NO_QFORKIMPL
#include "win32fixes.h"
#include <stdbool.h>
#include "UI.h"
#include <stdlib.h>
#include <stdio.h>
#include "Login.h"
#include "define.h"
#include <conio.h>

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

void setter()
{
	InitConnection();
	printf("command!\n");
	char buffer[200];
	int index = 0;
	bool finish = false;
	while (!finish)
	{
		char c = getch();
		switch (c)
		{
			case '\b':
				printf("\b \b");
				index--;
				if (index < 0) index = 0;
				break;
			case 13:
				buffer[index] = '\0';
				finish = true;
				break;
			case '\0':
				break;
			default:
				buffer[index] = c;
				printf("%c", buffer[index]);
				index++;
				break;
		}
	}
	redisReply* reply = redisCommand(context, buffer);
	printf("\nstatus/result:%s\n", reply->str);
	system("pause");
}