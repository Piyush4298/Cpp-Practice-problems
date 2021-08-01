#include<iostream>
#include<vector>
using namespace std;

struct Node
{   
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void findPathUtil(Node *root, vector<vector<int>> &v, vector<int> currSum)
{
    if(root == NULL)
        return;
    currSum.push_back(root->data);
    if(root->left == NULL && root->right == NULL)
    {
        v.push_back(currSum);
        return;
    }
    findPathUtil(root->left, v, currSum);
    findPathUtil(root->right, v, currSum);
}

vector<vector<int>> findPaths(Node *root)
{
    vector<vector<int>> v;
    vector<int> currSum;
    findPathUtil(root, v, currSum);
    return v;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    vector<vector<int>> p = findPaths(root);
    for(auto x : p)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}