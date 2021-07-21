/*
I/P:
            10
          /    \
        20      30
       /  \       \ 
    40     50      70 

O/P : 10 20 30 70 50 40 
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

void spiralTraversal(Node *root)
{
    if(root == NULL)
        return; 
    queue<Node*> q;
    stack<int> s;
    bool reversed = true;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if(reversed)
                s.push(curr->data);
            else
                cout << curr->data << " ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        if(reversed)
        {
            while(!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reversed = !reversed;
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

    spiralTraversal(root);
    return 0;
}