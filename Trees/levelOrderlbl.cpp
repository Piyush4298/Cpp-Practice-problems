// level order traversal line by line
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

void levelOrderLineByLine(Node *root)
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
            cout << curr->data << " ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        cout << "\n";
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

    levelOrderLineByLine(root);
    return 0;
}