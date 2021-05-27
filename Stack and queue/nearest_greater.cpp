/*
Given an array of number, we have to print numbers nearest greater to its right

i/p : arr[] = {5, 15, 10, 8, 12, 18}
o/p :         {15, 18, 12, 12, 18, -1}

*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> nextGreaterToRight(int arr[], int n)
{
    vector<int> v;
    stack<int> s;
    for(int i = n-1; i >= 0; i--)
    {
        if(s.empty())
            v.push_back(-1);
        else if(arr[i] < s.top())
            v.push_back(s.top());
        else{
            while (!s.empty() && arr[i] >= s.top())
            {
                s.pop();
            }
            if(s.empty())
                v.push_back(-1);
            else if(arr[i] < s.top())
                v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}
int main()
{
    int arr[] = {5, 15, 10, 8, 12, 18};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> res = nextGreaterToRight(arr, n);

    for(auto x : res)
        cout << x << " ";
    
    return 0;
}