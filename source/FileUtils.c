#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructcher.h"
#include "../header/FileUtils.h"
#include "../header/tree.h"

void writeFile(Task task_array[], int numTasks, const char *filename)
{
    char *str = NULL;
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < numTasks; i++)
    {
        str = tasktostring(task_array[i]);
        fprintf(file, "%s\n", str);
        free(str);
        str = NULL;
    }

    fclose(file);
}
Nodeptr readFile(int *numTasks, const char *filename)
{
    int i = 0;
    char *str = NULL;
    size_t len = 0;
    Taskptr task;
     short read;
     Nodeptr head = NULL;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }
    printf("File %s opened successfully.\n", filename);
   while ((read = getline(&str, &len, file)) != -1) 
    {

        task = convertTask(str);
        insertNode(&head, task);

    }
    fclose(file);
    return head;
}