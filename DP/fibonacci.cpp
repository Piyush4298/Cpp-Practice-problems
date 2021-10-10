#include<iostream>
using namespace std;

int fibMemoised(int dp[], int n)
{
    if(n == 0 || n == 1)
        return n;
    
    if(dp[n] != 0)
        return dp[n];
    
    dp[n] = fibMemoised(dp, n-1) + fibMemoised(dp, n-2);
    return dp[n];
}

int fibTabulation(int dp[], int n)
{
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n = 10;

    int dp1[n+1] = {0};
    int dp2[n+1] = {0};
    cout << fibMemoised(dp1, n) << endl;
    cout << fibTabulation(dp2, n);
    return 0;
}