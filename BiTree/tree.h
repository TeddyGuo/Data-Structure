#ifndef TREE_H
#define TREE_H

// NS: Node Structure
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}NS;

struct Node* search(struct Node*, int);
struct Node* insert(struct Node*, int);
NS* del(struct Node*, int);
struct Node* findLargestNode(struct Node*);
int height(struct Node*);
int totalNodes(struct Node*);
int totalExternalNodes(struct Node*);
NS* mirrorImage(struct Node*);
NS* smallMirrorImage(NS*);

#endif