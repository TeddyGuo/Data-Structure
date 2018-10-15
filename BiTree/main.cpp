#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    Node* a = new Node();
    a->val = 123;
    a->left = new Node();
    a->left->val = 32;
    a->right = new Node();
    a->right->val = 155;

    // search part
    Node* temp = search(a, 32);
    printf("%d\n", temp->val);

    // insert part
    Node* b = NULL; 
    insert(b, 128);
    printf("%d\n", b->val);
    insert(b, 32);
    printf("%d\n", b->left->val);

    // 

    return 0;
}
