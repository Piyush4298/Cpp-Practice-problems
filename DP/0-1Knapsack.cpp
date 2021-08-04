/*
Input:
N = 4
W = 7
values[] = {1, 4, 5, 6}
weight[] = {1, 3, 4, 7}
Output: 9
*/
#include<iostream>
#include<cstring>
using namespace std;

//Recursive sol
// int knapSack(int wt[], int val[], int n, int W)
// {
//     if(n == 0 || W == 0)
//         return 0;
//     else if(wt[n-1] <= W)
//     {
//         return max(val[n-1]+knapSack(wt, val, n-1, W-wt[n-1]), knapSack(wt, val, n-1, W));
//     }
//     else
//         return knapSack(wt, val, n-1, W);
// }
int knapSack(int wt[], int val[], int n, int W)
{
    int dp[n+1][W+1];
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < W+1; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < W+1; j++)
        {
            if(wt[i-1] <= j)
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

int main()
{
    int weight[] = {1, 3, 4, 7};
    int values[] = {1, 4, 5, 6};
    int n = sizeof(weight)/sizeof(weight[0]);
    int W = 7;
    int ans = knapSack(weight, values, n, W);
    cout << "Maximum profit value: " << ans;
    return 0;
}