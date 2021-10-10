/*Given n integers representing number of stairs in staircase
You are on 0th step and required to climb to the top.
In one move you are allowed to climb 1 or 2 stairs.
Find number of different paths via which you can climb to top.
I/P : 5
O/P : 8
*/

#include<iostream>
using namespace std;

int climbStairRecursion(int n)
{
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    return climbStairRecursion(n-1) + climbStairRecursion(n-2);
}

int climbStairMemoize(int n, int dp[])
{
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    if(dp[n] != 0)
        return dp[n];
    dp[n] = climbStairMemoize(n-1, dp) + climbStairMemoize(n-2, dp);
    return dp[n];
}

int climbStairTabulation(int n)
{
    int dp[n+1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
            dp[i] = dp[i-1];
        else
            dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n = 5;
    cout << climbStairRecursion(n) << "\n";
    int dp[n+1] = {0};
    cout << climbStairMemoize(n, dp) << "\n";
    cout << climbStairTabulation(n);
    return 0;
}