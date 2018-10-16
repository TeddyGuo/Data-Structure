#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main()
{
    struct Node* a = (struct Node*) malloc(sizeof(struct Node));
    a->val = 123;
    a->left = (struct Node*) malloc(sizeof(struct Node));;
    a->left->val = 32;
    a->right = (struct Node*) malloc(sizeof(struct Node));;
    a->right->val = 155;

    // search part
    struct Node* temp = search(a, 123);
    printf("%d\n", temp->val);

    // insert part
    struct Node* b = NULL;
    b = insert(b, 123);
    printf("%d\n", b->val);
    b = insert(b, 321);
    printf("%d\n", b->right->val);
    b = insert(b, 32);
    b = insert(b, 64);

    // del part
    // single one node
    // b = del(b, 321);
    // if (b->right != NULL)
    //     printf("%d\n", b->right->val);
    // else
    //     printf("Yes\n");
    // one child
    // b = del(b, 123);
    // printf("%d\n", b->val);
    // two children
    b = del(b, 123);
    printf("%d\n", b->val);

    

    return 0;
}
