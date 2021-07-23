/*
I/P:
            10
          /    \
        20      30
       /  \       \ 
    40     50      70 

O/P : 10 30 70 20 50 40
*/
#include<iostream>
#include<queue>
#include<stack>
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

void diagonalTraversal(Node *root)
{
    if(root == NULL)
        return; 
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        while(curr != NULL)
        {
            if(curr->left != NULL)
                q.push(curr->left);
            cout << curr->data << " ";
            curr = curr->right;
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

    diagonalTraversal(root);
    return 0;
}