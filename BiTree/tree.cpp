#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <stddef.h>
#include <vector>
#include <iostream>
using namespace std;

void postorder(NS* tree, vector<int>& arr)
{
    if (tree != NULL)
    {
        postorder(tree->left, arr);
        postorder(tree->right, arr);
        arr.push_back(tree->val);
    }
}
void preorder(NS* tree, vector<int>& arr)
{
    if (tree != NULL)
    {
        arr.push_back(tree->val);
        preorder(tree->left, arr);
        preorder(tree->right, arr);
    }
}
void inorder(NS* tree, vector<int>& arr)
{
    if (tree != NULL)
    {
        inorder(tree->left, arr);
        arr.push_back(tree->val);
        inorder(tree->right, arr);
    }
}

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
        NS* temp = findLargestNode(tree->left);
        tree->val = temp->val;
        tree->left = del(tree->left, temp->val);

        free(temp);
    }
    else
    {
        if (tree->left == NULL && tree->right == NULL)
            tree = NULL;
        else if (tree->left == NULL)
            tree = tree->right;
        else
            tree = tree->left;
    }

    return tree;
}
NS* delMin(NS* tree, int val)
{
    if (tree == NULL)
    {
        // printf("VAL not found in the tree.\n");
    }
    else if (val < tree->val)
    {
        tree->left = delMin(tree->left, val);
    }
    else if (val > tree->val)
    {
        tree->right = delMin(tree->right, val);
    }
    else
    {
        if (tree->left == NULL)
        {
            NS* temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            NS* temp = tree->left;
            free(tree);
            return temp;
        }
        else
        {
            NS* temp = findSmallestNode(tree->right);
            // cout << "Smallest: " << temp->val << endl;
            tree->val = temp->val;
            tree->right = delMin(tree->right, temp->val);
        }
    }

    return tree;
}
struct Node* findLargestNode(struct Node* node)
{
    NS* cur = node;
    while (cur->right != NULL)
        cur = cur->right;
    return cur;
}
NS* findSmallestNode(NS* node)
{
    NS* cur = node;
    while (cur->left != NULL)
        cur = cur->left;
    return cur;
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
int totalInternalNodes(NS* tree)
{
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
    {
        return 0;
    }
    else
    {
        if (tree->left != NULL && tree->right != NULL) 
            return totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1;
        else if (tree->left != NULL)
            return totalInternalNodes(tree->left) + 1;
        else
            return totalInternalNodes(tree->right) + 1;
    }
}

NS* mirrorImage(struct Node* tree)
{
    if (tree != NULL)
    {
        tree->left = smallMirrorImage(tree->left);
        tree->right = smallMirrorImage(tree->right);
        struct Node* temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
    else
        printf("The tree is empty\n");

    return tree;
}

NS* smallMirrorImage(NS* node)
{
    if (node != NULL)
    {
        node->left = smallMirrorImage(node->left);
        node->right = smallMirrorImage(node->right);
        struct Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

    return node;
}