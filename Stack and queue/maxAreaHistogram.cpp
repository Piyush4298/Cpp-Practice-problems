/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.
I/P : N = 7 arr[] = {6,2,5,4,5,1,6}
O/P : 12
*/
#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;

vector<int> nearestSmallerToLeft(int arr[], int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
    int pseudo_point = -1;
    for(int i = 0; i < n; i++)
    {
        if(s.empty())
            res.push_back(pseudo_point);
        else if(s.top().first < arr[i])
            res.push_back(s.top().second);
        else{
            while(!s.empty() && s.top().first >= arr[i])
                s.pop();
            if(s.empty())
                res.push_back(pseudo_point);
            else if(s.top().first < arr[i])
                res.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    return res;
}

vector<int> nearestSmallerToRight(int arr[], int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
    int pseudo_point = n;
    for(int i = n-1; i >= 0; i--)
    {
        if(s.empty())
            res.push_back(pseudo_point);
        else if(s.top().first < arr[i])
            res.push_back(s.top().second);
        else{
            while(!s.empty() && s.top().first >= arr[i])
                s.pop();
            if(s.empty())
                res.push_back(pseudo_point);
            else if(s.top().first < arr[i])
                res.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    reverse(res.begin(), res.end());
    return res;
}

int maxAreaOfHistogram(int arr[], int n)
{
    vector<int> width(n);
    vector<int> area(n);
    
    vector<int> left = nearestSmallerToLeft(arr, n);
    vector<int> right = nearestSmallerToRight(arr, n);
    for(int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    for(int i = 0; i < n; i++)
    {
        area[i] = width[i]*arr[i];
    }
    for(auto x : area)
        cout << x << " ";
    auto maxArea = max_element(area.begin(), area.end());
    return *maxArea;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = maxAreaOfHistogram(arr, n);
    cout << "\nMax area of histogram : " << res;
    return 0;
}