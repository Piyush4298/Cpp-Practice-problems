/*
i/p :   50
       /   \
     30     70
    /  \   /  \
   10  40 60   80
    n1 = 40  n2 =60
o/p : 50
*/
#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

Node *lcaOfBst(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root->key > n1 && root->key > n2)
        return lcaOfBst(root->left, n1, n2);
    else if(root->key < n1 && root->key < n2)
        return lcaOfBst(root->right, n1, n2);
    else
        return root;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int n1 = 40, n2 = 60;
    Node *lca = lcaOfBst(root, n1, n2);
    cout << "LCA is : " << lca->key;
    return 0;
}