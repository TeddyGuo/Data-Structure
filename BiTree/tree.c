#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Node* search(struct Node* tree, int val)
{
    if (tree->val == val || tree == NULL)
    {
        return tree;
    }
    else
    {
        if (val < tree->val)
            return search(tree->left, val);
        else
            return search(tree->right, val);
    }
}
void insert(Node* tree, int val)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(Node));
        tree->val = val;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        if (val < tree->val)
            insert(tree->left, val);
        else
            insert(tree->right, val);
    }
    return;
}
void del(Node* tree, int val)
{
    if (tree == NULL)
    {
        printf("VAL not found in the tree. jjininder, suck my dick\n");
    }
    else if (val < tree->val)
    {
        del(tree->left, val);
    }
    else if (val > tree->val)
    {
        del(tree->right, val);
    }
    else if (tree->left != NULL && tree->right != NULL)
    {
        Node* temp = findLargestNode(tree->left);
        tree->val = temp->val;
        del(tree->left, temp->val);
    }
    else
    {
        Node* temp = tree;
        if (tree->left == NULL && tree->right == NULL)
        {
            tree = NULL;
        }
        else if (tree->left != NULL)
            tree = tree->left;
        else
            tree = tree->right;

        free(temp);
    }
}
Node* findLargestNode(Node* node)
{
    Node* max = node;
    while (node != NULL)
    {
        if (max->val < node->val)
        {
            max = node;
        }
        node = node->right;
    }
    return max;
}

int height(Node* tree)
{
    if (tree == NULL) return 0;
    else
    {
        int leftHeight = height(tree->left);
        int rightHeight = height(tree->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}
int totalNodes(Node* tree)
{
    if (tree == NULL)
        return 0;
    else
        return totalNodes(tree->left) + totalNodes(tree->right) + 1;
}
int totalExternalNodes(Node* tree)
{
    if (tree == NULL)
        return 0;
    else if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else
    {
        return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);  
    }
}

void mirrorImage(Node* tree)
{
    if (tree != NULL)
    {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        Node* temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
    else
        printf("The tree is empty\n");
}