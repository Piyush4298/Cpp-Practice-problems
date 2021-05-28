/*
Given an array of number, we have to print numbers nearest greater to its left.

i/p : arr[] = {5, 15, 10, 8, 12, 18}
o/p :         {-1, -1, 15, 10, 15, -1}
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nearestGreaterToLeft(int arr[], int n)
{
    vector<int> res;
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        if(s.empty())
            res.push_back(-1);
        else if(s.top() > arr[i])
            res.push_back(s.top());
        else
        {
            while(!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            if(s.empty())
                res.push_back(-1);
            else if(s.top() > arr[i])
                res.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return res;
}
int main()
{
    int arr[] = {5, 15, 10, 8, 12, 18};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> res = nearestGreaterToLeft(arr, n);

    for(auto x : res)
        cout << x << " ";
    return 0;
}