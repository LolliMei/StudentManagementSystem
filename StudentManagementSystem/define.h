#pragma once

typedef int UserType;
#define STUDENT 1
#define TEACHER 2
#define ADMIN    3
#define UNKNOWN 0

#define ENTER 13
#define BACKSPACE '\b'
#define STREND '\0'

typedef struct
{
	char Name[30];
	int credit;
	int Score;
}Course;

typedef struct
{
	int termType;
	Course courses[25];
	int courseCount;
}ScoreTable;

typedef struct
{
	int grade;
	char id[20];
	char age[3];
	char birth[20];
	char name[20];
	char sex[4];
	int majorcode;
	char major[60];
	ScoreTable scoreTable[20];
	int tableCount;
}Student;

typedef struct
{
	char id[20];
	char age[3];
	char birth[20];
	char name[20];
	char sex[4];
	//����
	int exp;
	//רҵ����
	int majorcode;
	//רҵ����
	char major[60];
	//ְ��
	char level[20];
	//����id
	int courseid[10];
	//����
	char desc[1024];
}Teacher;

typedef struct
{
	int type;
	char username[20];
	int verify;
}User;