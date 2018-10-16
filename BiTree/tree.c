#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <stddef.h>

struct Node* search(struct Node* tree, int val)
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
struct Node* insert(struct Node* tree, int val)
{ 
    if (tree == NULL)
    {
        struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
        temp->val = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    else
    {
        if (val < tree->val)
            tree->left = insert(tree->left, val);
        else
            tree->right = insert(tree->right, val);
    }
    return tree;
}
NS* del(struct Node* tree, int val)
{
    if (tree == NULL)
    {
        printf("VAL not found in the tree.\n");
    }
    else if (val < tree->val)
    {
        tree->left = del(tree->left, val);
    }
    else if (val > tree->val)
    {
        tree->right = del(tree->right, val);
    }
    else if (tree->left != NULL && tree->right != NULL)
    {
        struct Node* temp = findLargestNode(tree->left);
        tree->val = temp->val;
        tree->left = del(tree->left, temp->val);

        free(temp);
    }
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            tree = NULL;
        }
        else if (tree->left != NULL)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return tree;
}
struct Node* findLargestNode(struct Node* node)
{
    struct Node* max = node;
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

int height(struct Node* tree)
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
int totalNodes(struct Node* tree)
{
    if (tree == NULL)
        return 0;
    else
        return totalNodes(tree->left) + totalNodes(tree->right) + 1;
}
int totalExternalNodes(struct Node* tree)
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

NS* mirrorImage(struct Node* tree)
{
    if (tree != NULL)
    {
        tree->left = mirrorImage(tree->left);
        tree->right = mirrorImage(tree->right);
        struct Node* temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
    else
        printf("The tree is empty\n");

    return tree;
}
