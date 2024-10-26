#ifndef DATASTRUCTCHER_H
#define DATASTRUCTCHER_H
#include "../header/StringUtils.h"
#include <stdlib.h>

typedef struct 
{
    short year;
    short month;
    short day;
    
} Date, * Dateptr;

typedef struct 
{
    short tag;
    char* description;
    Date TargetDate;
    Date CompDate;
} Task, * Taskptr;

char * tasktostring(Task task);

Date createTaskDate(short year, short month, short day);
Taskptr createTask(short tag, char* description, Date TargetDate, Date CompDate);
Taskptr convertTask(char * string);
int comperTask(Taskptr a, Taskptr b);
int freestask(Taskptr task);
#endif
