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
int insertNode(Nodeptr* root, Taskptr data)
{

    Nodeptr newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return 1;
    }

    int result = comperTask((*root)->data, data);
    if (result < 0) {
        insertNode(&((*root)->right), data);
    }
    else if (result > 0) {
        insertNode(&((*root)->left), data);
    }
    else {
        return  0;
    }

}

// Function to perform level order traversal to find the
// deepest rightmost node
// Function to delete a node in the binary tree
void deleteNode(Nodeptr* root, int data)
{
    Nodeptr temp,*anotherTemp;
    if (*root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    int result = comperTask((*root)->data, data);
    if(result == 0) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            freestask((*root)->data);
            free(*root);
            *root = NULL;
            return;
        }
    else {
             temp = (*root);
 
            if( (*root)->left == NULL )
                (*root) = (*root)->right;
 
            else if( (*root)->right == NULL)
                (*root) = (*root)->left;
            else {
                (*root) = (*root)->right;
                for(anotherTemp = root; (*anotherTemp)->left != NULL; anotherTemp = &(*anotherTemp)->left);   
                (*anotherTemp)->left = temp->left;
            }
            freestask(temp->data);
            free(temp);
        }
        }
        
    else if (result < 0) {
        insertNode(&((*root)->right), data);
    }
    else if (result > 0) {
        insertNode(&((*root)->left), data);
    }

}

// Function to search for a node in the binary tree
Nodeptr search(Nodeptr root, Taskptr data)
{
    if (root == NULL) {
        return NULL;
    }
    int result = comperTask(root->data, data);
    if(result == 0) {
        return root;
    }
    else if (result < 0) {
        search(root->right, data);
    }
    else if (result > 0) {
        insertNode(root->left, data);
    }
}
// function to perform inorder traversal in a binary tree
void inorderTraversal(Node* root)
{
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%s\n", tasktostring(*(root->data))); 
    inorderTraversal(root->right);
}
