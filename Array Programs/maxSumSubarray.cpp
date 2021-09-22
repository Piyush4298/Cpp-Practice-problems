#include<iostream>
using namespace std;

int maxSumSubarray(int arr[], int n, int k)
{
    int maxSum = INT_MIN, sum = 0;
    int i = 0, j = 0;
    while(j < n)
    {
        sum += arr[j];
        if(j-i+1 < k)
        {
            j++;
        }
        else
        {
            maxSum = max(maxSum, sum);
            sum = sum - arr[i];
            i++, j++;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {2, 5, 1, 8, 2, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << maxSumSubarray(arr, n, k);
    return 0;
}