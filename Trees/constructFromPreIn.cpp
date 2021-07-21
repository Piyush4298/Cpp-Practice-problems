#include<iostream>
#include<unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};
class Solution
{
    int idx;
    unordered_map<int, int> mp;
    Node *solve(int in[], int pre[], int lb, int ub)
    {
        if(lb > ub) 
            return NULL;
        Node *root = new Node(pre[idx++]);
        if(lb == ub)
            return root;
        int mid = mp[root->data];
        root->left = solve(in, pre, lb, mid-1);
        root->right = solve(in, pre, mid+1, ub);
        return root;
    }
    public:
    Node *convertIntoTree(int in[], int pre[], int n)
    {
        idx = 0;
        mp.clear();
        for(int i = 0; i < n; i++)
            mp[in[i]] = i;
        return solve(in, pre, 0, n-1);
    }

    void inorder(Node *root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};


int main()
{
    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int n = sizeof(in)/sizeof(in[0]);
    
    Solution ob;
    Node *root = ob.convertIntoTree(in, pre, n);
    ob.inorder(root);
    return 0;
}
