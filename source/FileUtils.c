#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructcher.h"
#include "../header/FileUtils.h"
#include "../header/tree.h"

int write_tasks(const char *filename) {
    Task task[]= {
        {1, "task1", {2020, 1, 1}, {-1, -1, -1}},
        {2, "task2", {2020, 1, 2}, {-1, -1, -1}},
        {3, "task3", {2020, 1, 3}, {-1, -1, -1}},
        {4, "task4", {2020, 4, 1}, {-1, -1, -1}},
        {5, "task5", {2020, 5, 1}, {-1, -1, -1}},
        {6, "task6", {2021, 1, 1}, {-1, -1, -1}},
        {7, "task7", {2024, 1, 1}, {-1, -1, -1}},
        {8, "task8", {2020, 2, 2}, {-1, -1, -1}},
        {9, "task9", {2020, 1, 10}, {-1, -1, -1}},
        {10, "task10", {2021, 11, 11}, {-1, -1, -1}}};
    writeFile(task, 10, filename); 
    return 0;
}
void writeFile(Task task_array[], int numTasks, const char *filename)
{
    printf("Creating %s file.\n", filename);
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
        write_tasks(filename);
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