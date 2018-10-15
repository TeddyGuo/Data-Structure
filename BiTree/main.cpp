#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstddef>
using namespace std;

int main()
{
    Node* a = (Node*) malloc(sizeof(Node));
    a->val = 123;
    a->left = (Node*) malloc(sizeof(Node));;
    a->left->val = 32;
    a->right = (Node*) malloc(sizeof(Node));;
    a->right->val = 155;

    // search part
    Node* temp = search(a, 123);
    printf("%d\n", temp->val);

    // insert part
    Node* b = nullptr;
    insert(b, 128); 
    printf("%d\n", b->val);
    insert(b, 32);
    printf("%d\n", b->left->val);
    insert(b, 300);
    printf("%d\n", b->right->val);

    // del part
    if (b == NULL) cout << "Yes" << endl;
    // printf("%d\n", search(b, 32)->val);

    return 0;
}
