#include "../header/datastructcher.h"
#include "../header/StringUtils.h"
#include <stdlib.h>
#include <stdio.h>
char * tasktostring(Task task)
{
    char *str = malloc(sizeof(char) * 1000);
    sprintf(str, "%d&%s&%d^%d^%d&%d^%d^%d", task.tag, task.description, task.TargetDate.year, task.TargetDate.month, task.TargetDate.day, task.CompDate.year, task.CompDate.month, task.CompDate.day);
    return str;
}
Date createTaskDate(short year, short month, short day){
    Date Date;
    Date.year = year;
    Date.month = month;
    Date.day = day;
    return Date;
}
Taskptr createTask(short tag, char* description, Date TargetDate, Date CompDate)
{
    Taskptr task = malloc(sizeof(Task));
    if(task == NULL) return NULL;
    task->description = malloc(strlen(description) + 1);
    task->tag = tag;
    strcpy(task->description, description);
    task->TargetDate = TargetDate;
    task->CompDate = CompDate;
    return task;
}

Taskptr convertTask(char * string)
{
    char** targetDatestring,**CompDatestring,**Splitstring;
    int SplitstringCount,CompDatestringcount,targetDatestringcount;
    short tag;
    char* description;
    Date targetDate,CompDate;
    Splitstring = Split(string,"&",&SplitstringCount);
    tag = atoi(Splitstring[0]);
    description = (char*)malloc(strlen(Splitstring[1])+1);
    strcpy(description,Splitstring[1]);
    targetDatestring = Split(Splitstring[2],"^",&targetDatestringcount);
    targetDate =createTaskDate(atoi(targetDatestring[0]),atoi(targetDatestring[1]),atoi(targetDatestring[2]));
    CompDatestring = Split(Splitstring[3],"^",&CompDatestringcount);
    CompDate=createTaskDate(atoi(CompDatestring[0]),atoi(CompDatestring[1]),atoi(CompDatestring[2]));
    freeIneersplit(CompDatestring,CompDatestringcount);
    freeIneersplit(targetDatestring,targetDatestringcount);
    freeIneersplit(Splitstring,SplitstringCount);
    return createTask(tag,description,targetDate,CompDate);
    
    
}
int comperTask(Taskptr a, Taskptr b)
{
    int cmp;
    cmp = a->TargetDate.year - b->TargetDate.year;
    if(cmp != 0) return cmp;
    cmp = a->TargetDate.month - b->TargetDate.month;
    if(cmp != 0) return cmp;
    cmp = a->TargetDate.day - b->TargetDate.day;
    return cmp;


}
int freestask(Taskptr task)
{
    free(task->description);
    free(task);
    return 0;
}

