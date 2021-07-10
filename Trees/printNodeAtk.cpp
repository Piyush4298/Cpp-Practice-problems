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
        left = right = NULL;
    }
};

void printNodeAtK(Node *root, int k)
{
    if(root == NULL)
        return;
    if(k == 0)
        cout << root->data << " ";
    else
    {
        printNodeAtK(root->left, k-1);
        printNodeAtK(root->right, k-1);
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
    int k = 2;
    cout << "Node(s) at distance are: ";
    printNodeAtK(root, k);
    return 0;
}