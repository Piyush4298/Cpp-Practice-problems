/*
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Input : N = 8 arr[] = {0, -10, 1, 3, -20, -1, -2, 4}
Output: 2
Explanation: Smallest positive missing number is 2 -->(1, _, 3, 4).

Note : negative numbers don't have any role in this, so we ignore them.
*/

#include<iostream>
using namespace std;

int segregate(int arr[], int n)
{
    int i = 0, j = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j;
}

int findMissingPositive(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int x = abs(arr[i]);
        if(x-1 < n && arr[x-1]>0)
            arr[x-1] = -arr[x-1];
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
            return i+1;
    }
    return -1;
}

int missingNumber(int arr[], int n)
{
    int shift = segregate(arr, n);
    int arr2[n-shift];
    int j = 0;
    for(int i = shift; i < n; i++)
    {
        arr2[j] = arr[i];
        j++;
    }
    return findMissingPositive(arr2, j);
}

int main()
{
    int arr[] = {0, -10, 1, 3, -20, -1, -2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Smallest +ve missing number is: " << missingNumber(arr, n);
    return 0;
}