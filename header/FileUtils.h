#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "../header/datastructcher.h"
#include <stdio.h>
#include <stdlib.h>

void writeFile(Task task_array[], int numTasks, const char *filename);
void readFile(Taskptr task_array, int *numTasks, const char *filename);

#endif