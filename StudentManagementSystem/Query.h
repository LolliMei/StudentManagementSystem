#pragma once
#include "hiredis.h"
#include <stdarg.h>
#include <stdbool.h>
#include "define.h"
char* ConstructCommand(const char* format,...);
char* ConstructGetCommand(char* key);
char* ConstructSetCommand(char* key);
char* ConstructDelCommand(char* key);
bool HandleReply(redisReply* reply);
void LoadStudentInfo(Student* stud);
redisReply* GetCommandReply(char* key);
redisReply* SetCommandReply(char* key);
redisReply* DelCommandReply(char* key);

redisReply* ChangePasswordCommand(int type,char* username);

