#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructcher.h"
#include "../header/FileUtils.h"

int write_tasks() {
    Task task[]= {
        {1, "task1", {2020, 1, 1}, {-1, -1, -1}},
        {2, "task2", {2020, 1, 1}, {-1, -1, -1}},
        {3, "task3", {2020, 1, 1}, {-1, -1, -1}},
        {4, "task4", {2020, 1, 1}, {-1, -1, -1}},
        {5, "task5", {2020, 1, 1}, {-1, -1, -1}},
        {6, "task6", {2020, 1, 1}, {-1, -1, -1}},
        {7, "task7", {2020, 1, 1}, {-1, -1, -1}},
        {8, "task8", {2020, 1, 1}, {-1, -1, -1}},
        {9, "task9", {2020, 1, 1}, {-1, -1, -1}},
        {10, "task10", {2020, 1, 1}, {-1, -1, -1}}};
   // write_tasks_to_file(task, 10, "Task.txt"); 
    return 0;
}

int main() {
    Taskptr a = NULL;
    int b= 0;
    readFile(a, &b, "Task.txt");
    return 0;
}
