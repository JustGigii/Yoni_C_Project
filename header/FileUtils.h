#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "../header/datastructcher.h"
#include "../header/tree.h"
#include <stdio.h>
#include <stdlib.h>

void writeFile(Task task_array[], int numTasks, const char *filename);
Nodeptr readFile(int *numTasks, const char *filename);

#endif