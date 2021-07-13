#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

bool search(Node *root, int k)
{
    if(root == NULL)
        return false;
    if(root->key == k)
        return true;
    else if(root->key > k)
        return search(root->left, k);
    else
        return search(root->right, k);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    if(search(root, 10)) cout << "Found !";
    else cout << "Not found !";
    return 0;
}