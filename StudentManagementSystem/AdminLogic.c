#include "AdminLogic.h"
#include <conio.h>
#include <assert.h>
#include "Login.h"

extern User user;
extern redisContext* context;
extern bool UserExists(int type, char* usr);
extern char* InputUsername(int type);

//加载管理员资料
void LoadAdminInfo(Admin* admin)
{
	extern User user;
	redisReply* reply;
	redisContext* context = redisConnect("127.0.0.1", 6379);
	reply = (redisReply*)redisCommand(context, "get admin:%s:name", user.username);
	strcpy(admin->name, reply->str);

	reply = (redisReply*)redisCommand(context, "get admin:%s:sex", user.username);
	strcpy(admin->sex, reply->str);

	
	free(reply);
}

//显示管理员资料
void AdminProfile()
{
	Admin admin;
	LoadAdminInfo(&admin);
	printf("个人基本信息:\n");
	printf("姓名:%s\n", admin.name);
	printf("性别:%s\n", admin.sex);
	printf("工号:%s\n", user.username);
	system("pause");
}

//管理员修改模式选择菜单
inline void AdminModifyMenu()
{
	//选择类型
	printf("请选择修改对象:\n");
	printf("1:学生\n");
	printf("2:教师\n");
	printf("3:管理员\n");
	printf("0:退出\n");


}

//修改学生信息
void ModifyStudent()
{
	//声明对象
	redisReply* reply;
	char* origin;
	char value[50];

	//输入修改对象
	char* usrid = InputUsername(STUDENT);

	//显示菜单
	printf("1:修改姓名");
	printf("2:修改年龄");
	printf("3:修改性别");
	printf("4:修改生日");
	printf("5:修改专业");
	printf("6:修改年级");
	printf("7:退出");

	//处理修改
	bool Exit = false;
	while (!Exit)
	{
		//选择修改项目
		char choice = getch() - 48;
		switch (choice)
		{
			case PROFILE_NAME:
			{
				reply = redisCommand(context, "get student:%s:name", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:name %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_AGE:
			{
				reply = redisCommand(context, "get student:%s:age", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:age %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_SEX:
			{
				reply = redisCommand(context, "get student:%s:sex", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:sex %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_BIRTH:
			{
				reply = redisCommand(context, "get student:%s:birth", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:birth %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_MAJOR:
			{
				reply = redisCommand(context, "get student:%s:majorcode", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:majorcode %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_GRADE:
			{
				reply = redisCommand(context, "get student:%s:grade", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:grade %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}

			default:
				break;
		}
	}



}

//修改教师信息
void ModifyTeacher()
{
	//声明对象
	redisReply* reply;
	char* origin;
	char value[50];

	//输入修改对象
	char* usrid = InputUsername(TEACHER);

	//显示菜单
	printf("1:修改姓名");
	printf("2:修改年龄");
	printf("3:修改性别");
	printf("4:修改生日");
	printf("5:修改专业");
	printf("6:修改年级");
	printf("7:退出");

	//处理修改
	bool Exit = false;
	while (!Exit)
	{
		//选择修改项目
		char choice = getch() - 48;
		switch (choice)
		{
			case PROFILE_NAME:
			{
				reply = redisCommand(context, "get student:%s:name", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:name %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_AGE:
			{
				reply = redisCommand(context, "get student:%s:age", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:age %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_SEX:
			{
				reply = redisCommand(context, "get student:%s:sex", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:sex %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_BIRTH:
			{
				reply = redisCommand(context, "get student:%s:birth", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:birth %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_MAJOR:
			{
				reply = redisCommand(context, "get student:%s:majorcode", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:majorcode %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}
			case PROFILE_GRADE:
			{
				reply = redisCommand(context, "get student:%s:grade", usrid);
				origin = reply->str;
				printf("原信息为: '%s' \n", origin);
				printf("请输入新信息项:");
				scanf_s("%s", value, 50);
				printf("按 1 确认提交更改\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:grade %s", usrid, value);
					printf("已提交更改!");
				}
				printf("业务已完成,任意键继续");
				break;
			}

			default:
				break;
		}
	}
}

//修改管理员信息，仅个人
void ModifyAdmin()
{

}

//管理员修改信息上帝模式
void AdminModifyAny()
{
	while (1)
	{
		//显示菜单
		AdminModifyMenu();
		//输入类型
		int type = getchar() - 48;
		//分发
		switch (type)
		{
			case STUDENT:
				ModifyStudent();
				break;
			case TEACHER:
				ModifyTeacher();
				break;
			case ADMIN:
				ModifyAdmin();
				break;
			case 0:
				return;
			default:
				break;
		}
	}

}

//管理员修改密码
void AdminChangePassword()
{
	//校验原密码
	char origin[20] = { 0 };
	printf("请输入原密码");
	scanf_s("%s", origin, 20);
	char* cmd = ConstructCommand("get login:admin:%s", user.username);
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
			redisCommand(context, "set login:admin:%s %s", user.username, newPassword1);
		}

	}
	printf("业务完成，任意键返回!");
	getchar();
}

//管理员退出
void AdminExit()
{
	user.verify = 0;
	memset(user.username, 0, 20);
	user.type = UNKNOWN;
}