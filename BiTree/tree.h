#ifndef TREE_H
#define TREE_H

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* search(Node*, int);
void insert(Node*, int);
void del(Node*, int);
Node* findLargestNode(Node*);
int height(Node*);
int totalNodes(Node*);
int totalExternalNodes(Node*);
void mirrorImage(Node*);

#endif
