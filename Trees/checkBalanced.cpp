/*
Difference of heights of left and right subtrees shouldn't exceed 1.
I/P:
            10
          /    \
        20     -10
       /  \     
    -30    50
    /
   40      

O/P : Yes
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

int isBalanced(Node* root)
{
    if(root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if(lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if(rh == -1)
        return -1;
    if(abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh)+1;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(-10);
    root->left->right = new Node(50);
    root->left->left = new Node(-30);
    root->left->left->left = new Node(40);

    cout << (isBalanced(root)!=-1?"Yes" : "No");
}