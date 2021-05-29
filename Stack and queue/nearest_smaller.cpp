/*
Given an array, find nearest smaller elements to right
i/p : arr[] = {4, 5, 2, 10, 8} 
o/p : 2 2 -1 8 -1
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector<int> nearestSmallerToRight(int arr[], int n)
{
    stack<int> s;
    vector<int> res;
    for(int i = n-1; i>=0; i--)
    {
        if(s.empty())
            res.push_back(-1);
        else if(s.top() < arr[i])
            res.push_back(s.top());
        else
        {
            while(!s.empty() && s.top() >= arr[i])
                s.pop();
            if(s.empty())
                res.push_back(-1);
            else if(s.top() < arr[i])
                res.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> res = nearestSmallerToRight(arr, n);

    for(auto x : res)
        cout << x << " ";
    return 0;
}