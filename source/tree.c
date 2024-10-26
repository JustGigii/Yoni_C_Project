// Function to create a new node
#include <stdio.h>
#include <stdlib.h>
#include "../header/datastructcher.h"
#include "../header/tree.h"

Nodeptr createNode(Taskptr data)
{
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for inserting a node in a binary tree
void insertNode(Nodeptr* root, Taskptr data)
{
    Nodeptr newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level order traversal to find the appropriate place
    // for insertion
    Nodeptr temp;
    Nodeptr queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;

    while (front != rear) {
        temp = queue[++front];

        //  Insert new node as the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        // if left child is not missing push it to the queue
        else {
            queue[++rear] = temp->left;
        }
        // Insert new node as the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        // if right child is not missing push it to the
        // queue
        else {
            queue[++rear] = temp->right;
        }
    }
}

// Function to perform level order traversal to find the
// deepest rightmost node
Nodeptr getDeepestRightmostNode(Nodeptr root)
{
    Nodeptr temp;
    Nodeptr queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }
    return temp;
}

// Function for deleting deepest rightmost node in a binary
// tree
void deleteDeepestRightmostNode(Nodeptr root, Nodeptr dNode)
{
    Nodeptr temp;
    Nodeptr queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        if (temp == dNode) {
            temp = NULL;
            free(dNode);
            return;
        }

        if (temp->right != NULL) {
            if (temp->right == dNode) {
                temp->right = NULL;
                free(dNode);
                return;
            }
            else {
                queue[++rear] = temp->right;
            }
        }

        if (temp->left != NULL) {
            if (temp->left == dNode) {
                temp->left = NULL;
                free(dNode);
                return;
            }
            else {
                queue[++rear] = temp->left;
            }
        }
    }
}

// Function to delete a node in the binary tree
void deleteNode (Nodeptr* root, int data)
{
    if (*root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    if ((*root)->left == NULL && (*root)->right == NULL) {
        if (comperTask((*root)->data , data)==0) {
            free(*root);
            *root = NULL;
            return;
        }
        else {
            printf("Node not found.\n");
            return;
        }
    }

    Nodeptr temp;
    Nodeptr queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;
    Nodeptr keyNode = NULL;

    while (front != rear) {
        temp = queue[++front];

        if (temp->data == data) {
            keyNode = temp;
        }

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }

    if (keyNode != NULL) {
        Nodeptr deepestNode = getDeepestRightmostNode(*root);
        keyNode->data = deepestNode->data;
        deleteDeepestRightmostNode(*root, deepestNode);
    }
    else {
        printf("Node not found.\n");
    }
}

// Function to search for a node in the binary tree
Nodeptr search(Nodeptr root, int data)
{
    if (root == NULL) {
        return NULL;
    }

    Nodeptr temp;
    Nodeptr queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        if (comperTask(temp->data, data)) {
            return temp;
        }

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }
    return NULL;
}
// function to perform inorder traversal in a binary tree
void inorderTraversal(Node* root)
{
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%s ", tasktostring(*(root->data))); 
    inorderTraversal(root->right);
}
