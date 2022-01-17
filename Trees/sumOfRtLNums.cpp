/*
I/P:
            2
          /   \
         3     5
o/p : 48 (23 + 25)
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void sumOfDigits(Node* root, int &ans, int currVal)
{
    if(root == NULL) return;

    currVal = currVal*10 + root->data;
    if(root->left == NULL && root->right == NULL)
    {
        ans += currVal;
        return;
    }

    sumOfDigits(root->left, ans, currVal);
    sumOfDigits(root->right, ans, currVal);
}


int main()
{
    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(5);

    int ans = 0;
    sumOfDigits(root, ans, 0);
    cout << ans;
    return 0;
}