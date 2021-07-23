/*
i/p :   50
       /   \
     30     70
    /  \   /  \
   10  40 60   80

o/p : YES
*/

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

bool isBST(Node *root, int prev)
{
    if(root == NULL)
        return true;
    if(isBST(root->left, prev) == false)
        return false;
    if(root->key <= prev)
        return false;
    prev = root->key;
    return isBST(root->right, prev);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    root->right->left = new Node(49);
    root->right->right = new Node(80);

    if(isBST(root, INT_MIN))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}