#include <cstdlib>
#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}NS;

void postorder(NS*, vector<int>&);
void preorder(NS*, vector<int>&);
struct Node* insert(struct Node*, int);
NS* del(struct Node*, int, bool);
struct Node* findLargestNode(struct Node*);
NS* findSmallestNode(NS*);
int height(struct Node*);
int totalNodes(struct Node*);
int totalInternalNodes(NS*);
NS* mirrorImage(struct Node*);
NS* smallMirrorImage(NS*);

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
NS* del(struct Node* tree, int val, bool flag)
{
    if (tree == NULL)
    {
        printf("VAL not found in the tree.\n");
    }
    else if (val < tree->val)
    {
        tree->left = del(tree->left, val, flag);
    }
    else if (val > tree->val)
    {
        tree->right = del(tree->right, val, flag);
    }
    else if (tree->left != NULL && tree->right != NULL)
    {
        if (flag == true)
        {
            NS* temp = findLargestNode(tree->left);
            tree->val = temp->val;
            tree->left = del(tree->left, temp->val, true);

            free(temp);
        }
        else
        {
            NS* temp = findSmallestNode(tree->right);
            // cout << "Smallest: " << temp->val << endl;
            tree->val = temp->val;
            tree->right = del(tree->right, temp->val, false);

            free(temp);
        }
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

int main()
{
    int temp;
    int lineno = 0;
    int nodeno = 0;
    vector<int> nodeval;
    int X = 0, Y = 0;
    NS* root;
    NS* root1;
    delete root;
    delete root1;

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
    root = del(root, Y, true);
    preorder(root, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;

    arr.clear();
    root1 = del(root1, Y, false);
    preorder(root1, arr);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;

    return 0;
}