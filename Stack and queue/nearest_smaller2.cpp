/*
Given an array, find nearest smaller elements to left
i/p : arr[] = {4, 5, 2, 10, 8} 
o/p : -1 4 -1 2 2
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nearestSmallerToLeft(int arr[], int n)
{
    vector<int> res;
    stack<int> s;

    for(int i = 0; i < n; i++)
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
    return res;
}
int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> res = nearestSmallerToLeft(arr, n);

    for(auto x : res)
        cout << x << " ";
    return 0;
}