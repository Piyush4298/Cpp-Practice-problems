/*
Find first negative number in every window of size k
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> firstNegativeOfKSize(int arr[], int n, int k)
{
    int i = 0, j = 0;
    queue<int> q;
    vector<int> v;
    while(j < n)
    {
        if(arr[j] < 0)
            q.push(arr[j]);
        if(j-i+1 < k)
            j++;
        else
        {
            if(q.size() == 0){
                v.push_back(0);
                i++, j++;
            }
            else
            {
                v.push_back(q.front());
                if(arr[i] > 0)
                    i++;
                else
                {
                    q.pop();
                    i++;
                }
                j++;
            }
        }
    }
    return v;
}

int main()
{
    int arr[] = {12, -1, -7, 30, -15, 16, 28, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int> v = firstNegativeOfKSize(arr, n, k);
    for(auto x : v)
        cout << x << " ";
    return 0;
}