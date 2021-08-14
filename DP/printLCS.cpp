#include<iostream>
#include<stack>
using namespace std;

void longestCommonSubsequence(string a, string b)
{
    int m = a.size();
    int n = b.size();
    int dp[m+1][n+1];
    for(int i = 0; i < m+1; i++)
        dp[i][0] = 0;
    for(int j = 0; j < n+1; j++)
        dp[0][j] = 0;
    for(int i = 1; i < m+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    stack<char> s;
    int i = m, j = n;
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            s.push(a[i-1]);
            i--, j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

int main()
{
    string a = "abcdef";
    string b = "acbcf";
    longestCommonSubsequence(a, b);
    return 0;
}
