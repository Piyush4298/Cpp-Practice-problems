/*
If both children are present then their sum should be equal to parent
I/P:
            10
          /    \
        20     -10
       /  \     
    -30    50      

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

bool childSum(Node* root)
{
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if(root->left != NULL)
        sum += root->left->data;
    if(root->right != NULL)
        sum += root->right->data;
    return (root->data == sum && childSum(root->left) && childSum(root->right));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(-10);
    root->left->right = new Node(50);
    root->left->left = new Node(-30);

    cout << (childSum(root)==true?"Yes" : "No");
}