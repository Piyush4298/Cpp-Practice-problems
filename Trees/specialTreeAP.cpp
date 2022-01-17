/*
Find minimum number that should be added to each level to make sum of nodes of each level form an AP.
i/p :    1
        /  \ 
       11   5
      /      \
     2        10
      \
       50

o/p : [0, 0, 19, 4]
*/

#include<iostream>
#include<queue>
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



vector<int> specialTree(Node* root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    int level = -1;
    int sum = 0;
    int prev = 0;
    while(!q.empty())
    {
        int n = q.size();
        level++;
        int currSum = 0;
        int tempHelp = 0;
        for(int i = 0; i < n; i++)
        {
            Node* curr =  q.front();
            q.pop();
            currSum += curr->data;
            if(i == n-1)
            {
                if(level > 1)
                {
                    if(currSum - sum != prev)
                    {
                        tempHelp = prev - (currSum - sum);
                        ans.push_back(tempHelp);
                    }
                    else
                        ans.push_back(0);
                }
                else{
                    ans.push_back(0);
                }
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(level == 1)
            prev =  currSum - sum;
        sum = currSum + tempHelp;
    }

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(11);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->right->right = new Node(10);
    root->left->left->right = new Node(50);

    vector<int> ans = specialTree(root);
    for(auto i : ans)
        cout << i << " ";
    return 0;
}