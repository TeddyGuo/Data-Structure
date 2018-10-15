#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Node* a = malloc(sizeof(Node));
    a->val = 123;
    a->left = malloc(sizeof(Node));
    a->left->val = 32;
    a->right = malloc(sizeof(Node));
    a->right->val = 155;

    // search part
    Node* temp = search(a, 32);
    printf("%d\n", temp->val);

    // insert part
    Node* b;
    insert(b, 128);
    printf("%d\n", b->val);
    insert(b, 32);
    printf("%d\n", b->left->val);

    // 

    return 0;
}