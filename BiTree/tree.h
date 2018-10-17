#ifndef TREE_H
#define TREE_H
#include <vector>

using namespace std;

// NS: Node Structure
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}NS;

void postorder(NS*, vector<int>&);
void preorder(NS*, vector<int>&);
void inorder(NS*, vector<int>&);
struct Node* search(struct Node*, int);
struct Node* insert(struct Node*, int);
NS* del(struct Node*, int);
NS* delMin(NS*, int);
struct Node* findLargestNode(struct Node*);
NS* findSmallestNode(NS*);
int height(struct Node*);
int totalNodes(struct Node*);
int totalExternalNodes(struct Node*);
int totalInternalNodes(NS*);
NS* mirrorImage(struct Node*);
NS* smallMirrorImage(NS*);

#endif