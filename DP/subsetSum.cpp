#include<iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    bool dp[n+1][sum+1];
    for(int i =0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1; j++)
        {
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {10, 5, 2, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 8;

    // check whether any subset of arr contains the sum 
    bool flag = subsetSum(arr, n, sum);
    cout <<"Is sum present in any subset? " << (flag==1?"YES":"NO");
    return 0;
}