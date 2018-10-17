#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int temp;
    int lineno = 0;
    int nodeno = 0;
    vector<int> nodeval;
    int X = 0, Y = 0;
    NS* root;
    NS* root1;

    // input
    cin >> nodeno;

    int count = 0;
    while (count < nodeno)
    {
        cin >> temp;
        nodeval.push_back(temp);
        root = insert(root, nodeval[count]);
        root1 = insert(root1, nodeval[count]);
        count++;
    }

    cin >> X; cin >> Y;

    vector<int> arr;
    // print post-order traversal
    postorder(root, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;

    arr.clear();
    // mirror post order
    root = mirrorImage(root);
    postorder(root, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;

    arr.clear();
    // print out pre-order traversal after root inserts a new node X
    root = mirrorImage(root); // reverse again to get original tree
    root = insert(root, X);
    root1 = insert(root1, X); // another root for useing at the end part
    preorder(root, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;

    // print out height of the tree
    cout << height(root) << endl;
    // print out total nodes
    cout << totalNodes(root) << endl;
    // print out internal nodes
    cout << totalInternalNodes(root) << endl;
    // print out the largest number
    cout << findLargestNode(root)->val << endl;
    // print out the smallest number
    cout << findSmallestNode(root)->val << endl;

    arr.clear();
    // print out two different ans about pre-order after root delete Y (maybe the same one)
    // I think it is not about preorder instead of inorder X I got wrong ans
    root = del(root, Y);
    preorder(root, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;

    arr.clear();
    root1 = delMin(root1, Y);
    preorder(root1, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1];

    return 0;
}
