#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int maxInBinaryTree(Node *root)
{
    if(root == NULL)
        return INT_MIN;
    else
        return max(root->data, max(maxInBinaryTree(root->left), maxInBinaryTree(root->right)));
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->left = new Node(60);

    cout << "Maximum in given tree: " << maxInBinaryTree(root);

}