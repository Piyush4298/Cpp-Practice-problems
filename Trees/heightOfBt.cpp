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

int heightOfBT(Node *root)
{
    if(root == NULL)
        return 0;
    else
        return max(heightOfBT(root->left), heightOfBT(root->right)) + 1;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->left = new Node(60);

    cout << "Height of given tree: " << heightOfBT(root);

}