/*
I/P:
            10
          /    \
        20      30
       /  \       \ 
    40     50      70 

O/P : 10 30 70
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

void rightViewOfBinaryTree(Node *root)
{
    if(root == NULL)
        return;
    queue<Node *> q;
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
            if(curr->right)
                q.push(curr->right);
            if(curr->left)
                q.push(curr->left);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);

    rightViewOfBinaryTree(root);
    return 0;
}
