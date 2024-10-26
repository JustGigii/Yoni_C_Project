#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructcher.h"
#include "../header/FileUtils.h"
#include "../header/tree.h"



int main() {
    Nodeptr head = NULL;
    Taskptr a = NULL;
    int b= 0;
    head=readFile(&b, "Task.txt");
    inorderTraversal(head);
    return 0;
}
