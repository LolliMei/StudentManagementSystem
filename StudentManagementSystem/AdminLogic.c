#include "AdminLogic.h"
#include <conio.h>
#include <assert.h>
#include "Login.h"

extern User user;
extern redisContext* context;
extern bool UserExists(int type, char* usr);
extern char* InputUsername(int type);

//���ع���Ա����
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

//��ʾ����Ա����
void AdminProfile()
{
	Admin admin;
	LoadAdminInfo(&admin);
	printf("���˻�����Ϣ:\n");
	printf("����:%s\n", admin.name);
	printf("�Ա�:%s\n", admin.sex);
	printf("����:%s\n", user.username);
	system("pause");
}

//����Ա�޸�ģʽѡ��˵�
inline void AdminModifyMenu()
{
	//ѡ������
	printf("��ѡ���޸Ķ���:\n");
	printf("1:ѧ��\n");
	printf("2:��ʦ\n");
	printf("3:����Ա\n");
	printf("0:�˳�\n");


}

//�޸�ѧ����Ϣ
void ModifyStudent()
{
	//��������
	redisReply* reply;
	char* origin;
	char value[50];

	//�����޸Ķ���
	char* usrid = InputUsername(STUDENT);

	//��ʾ�˵�
	printf("1:�޸�����");
	printf("2:�޸�����");
	printf("3:�޸��Ա�");
	printf("4:�޸�����");
	printf("5:�޸�רҵ");
	printf("6:�޸��꼶");
	printf("7:�˳�");

	//�����޸�
	bool Exit = false;
	while (!Exit)
	{
		//ѡ���޸���Ŀ
		char choice = getch() - 48;
		switch (choice)
		{
			case PROFILE_NAME:
			{
				reply = redisCommand(context, "get student:%s:name", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:name %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_AGE:
			{
				reply = redisCommand(context, "get student:%s:age", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:age %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_SEX:
			{
				reply = redisCommand(context, "get student:%s:sex", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:sex %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_BIRTH:
			{
				reply = redisCommand(context, "get student:%s:birth", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:birth %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_MAJOR:
			{
				reply = redisCommand(context, "get student:%s:majorcode", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:majorcode %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_GRADE:
			{
				reply = redisCommand(context, "get student:%s:grade", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:grade %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}

			default:
				break;
		}
	}



}

//�޸Ľ�ʦ��Ϣ
void ModifyTeacher()
{
	//��������
	redisReply* reply;
	char* origin;
	char value[50];

	//�����޸Ķ���
	char* usrid = InputUsername(TEACHER);

	//��ʾ�˵�
	printf("1:�޸�����");
	printf("2:�޸�����");
	printf("3:�޸��Ա�");
	printf("4:�޸�����");
	printf("5:�޸�רҵ");
	printf("6:�޸��꼶");
	printf("7:�˳�");

	//�����޸�
	bool Exit = false;
	while (!Exit)
	{
		//ѡ���޸���Ŀ
		char choice = getch() - 48;
		switch (choice)
		{
			case PROFILE_NAME:
			{
				reply = redisCommand(context, "get student:%s:name", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:name %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_AGE:
			{
				reply = redisCommand(context, "get student:%s:age", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:age %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_SEX:
			{
				reply = redisCommand(context, "get student:%s:sex", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:sex %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_BIRTH:
			{
				reply = redisCommand(context, "get student:%s:birth", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:birth %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_MAJOR:
			{
				reply = redisCommand(context, "get student:%s:majorcode", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:majorcode %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}
			case PROFILE_GRADE:
			{
				reply = redisCommand(context, "get student:%s:grade", usrid);
				origin = reply->str;
				printf("ԭ��ϢΪ: '%s' \n", origin);
				printf("����������Ϣ��:");
				scanf_s("%s", value, 50);
				printf("�� 1 ȷ���ύ����\n");
				if (getch() - 48 == 1)
				{
					redisCommand(context, "set student:%s:grade %s", usrid, value);
					printf("���ύ����!");
				}
				printf("ҵ�������,���������");
				break;
			}

			default:
				break;
		}
	}
}

//�޸Ĺ���Ա��Ϣ��������
void ModifyAdmin()
{

}

//����Ա�޸���Ϣ�ϵ�ģʽ
void AdminModifyAny()
{
	while (1)
	{
		//��ʾ�˵�
		AdminModifyMenu();
		//��������
		int type = getchar() - 48;
		//�ַ�
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
	memset(user.username, 0, 20);
	user.type = UNKNOWN;
}