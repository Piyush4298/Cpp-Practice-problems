/*
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s
Input:  0 1 1 0
        1 1 1 1
        1 1 1 1
        1 1 0 0

Output : 8
*/
#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int> &arr, int n)
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

vector<int> nearestSmallerToRight(vector<int> &arr, int n)
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

int maxAreaOfHistogram(vector<int> &arr, int n)
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

    auto maxArea = max_element(area.begin(), area.end());
    return *maxArea;
}

int main()
{
    vector<vector<int>> v = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    for(auto x : v)
    {
        for(auto y : x)
            cout << y << " ";
        cout << endl;
    }
    int m = v.size();
    int n = v[0].size();
    int maxArea = 0;
    vector<int> res;
    for(int j = 0; j < n; j++)
    {
        res.push_back(v[0][j]);
    }
    maxArea = maxAreaOfHistogram(res, res.size());

    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] == 0)
                res[j] = 0;
            else
                res[j] += v[i][j];
        }
        maxArea = max(maxArea, maxAreaOfHistogram(res, res.size()));
    }

    cout << "MAX area of Binary matrix is : " << maxArea;
    return 0;
}