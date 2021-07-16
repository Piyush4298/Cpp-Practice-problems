/*
I/P:
            10
          /    \
        20      30
         \        \
          50       70 

O/P : 10 20 50

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

void leftViewOfBinaryTree(Node *root)
{
    if(root == NULL)
        return; 
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if(i == 0)
                cout << curr->data << " ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(50);
    root->right->right = new Node(70);

    leftViewOfBinaryTree(root);
    return 0;
}