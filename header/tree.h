#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructcher.h"

typedef struct tree
{
    Taskptr data;
    struct tree *left;
    struct tree *right;
} Node, *Nodeptr;

// Function to create a new node
Node* createNode(Taskptr data);

// Function for inserting a node in a binary tree
int insertNode(Nodeptr* root, Taskptr data);

// Function to delete a node in the binary tree
void deleteNode(Nodeptr* root, int data);

void inorderTraversal(Node* root);

#endif