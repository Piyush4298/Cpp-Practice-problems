/*
I/P:
            10
           /   \
         20     30
           \      \
            50     70
           / 
         10

O/P : 20 10
      10 50
      30
      70

*/

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<map>
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

void verticalOrderTraversal(Node *root)
{
    if(root == NULL)
        return; 
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        Node *curr = q.front().first;
        int h = q.front().second;
        q.pop();
        mp[h].push_back(curr->data);
        if(curr->left)
            q.push({curr->left, h-1});
        if(curr->right)
            q.push({curr->right, h+1});
    }
    for(auto x : mp)
    {
        for(auto y : x.second)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    root->left->right->left = new Node(10);
    verticalOrderTraversal(root);
    return 0;
}