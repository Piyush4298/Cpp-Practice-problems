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

bool equalSumPartition(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    
    if(sum % 2 != 0)
        return false;
    return subsetSum(arr, n, sum/2);
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    // check if we can split array into two, such that their sum is equal.
    bool flag = equalSumPartition(arr, n);
    cout << (flag==1?"YES":"NO");
    return 0;
}