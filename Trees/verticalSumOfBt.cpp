/*
I/P:
            10
           /   \
         20     30
           \      \
            50     70
           / 
         10

O/P : 30 60 30 70

*/

#include<iostream>
#include<queue>
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

void verticalSum(Node *root)
{
    if(root == NULL)
        return; 
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        Node *curr = q.front().first;
        int h = q.front().second;
        q.pop();
        if(mp.find(h) == mp.end())
        {
            mp[h] = curr->data;
        }
        else{
            mp[h] += curr->data;
        }
        if(curr->left)
            q.push({curr->left, h-1});
        if(curr->right)
            q.push({curr->right, h+1});
    }
    for(auto x : mp)
        cout << x.second << " ";
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    root->left->right->left = new Node(10);
    verticalSum(root);
    return 0;
}