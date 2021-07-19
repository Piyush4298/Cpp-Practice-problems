/*
Difference of heights of left and right subtrees shouldn't exceed 1.
I/P:
            10
          /    \
        20     -10
       /  \     / \
    -30    50  70  40
    /        \
   40         60

O/P : 4
*/
#include<iostream>
#include<queue>
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

int  maxWidth(Node* root)
{
    if(root == NULL)
        return 0;
    queue<Node*> q;
    q.push(root);
    int res = 0;
    while(!q.empty())
    {
        int n = q.size();
        res = max(res, n);
        for(int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return res; 
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(-10);
    root->right->left = new Node(70);
    root->right->right = new Node(40);
    root->left->right = new Node(50);
    root->left->left = new Node(-30);
    root->left->left->left = new Node(40);
    root->left->right->right = new Node(60);
    

    cout << "max width is: " << maxWidth(root);
    return 0;
}