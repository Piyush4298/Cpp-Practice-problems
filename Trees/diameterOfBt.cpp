/*
I/P:
            10
          /    \
        20      60
       /  \     
     30    50      
    /
   40 
O/P : 5
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int diameterOfBinaryTree(Node* root, int &res)
{
    if(root == NULL)
        return 0;
    int lh = diameterOfBinaryTree(root->left, res);
    int rh = diameterOfBinaryTree(root->right, res);
    res = max(res, 1+lh+rh);
    return 1+max(lh, rh);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->right = new Node(50);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    int res = 0;
    diameterOfBinaryTree(root, res);
    cout << res;
}