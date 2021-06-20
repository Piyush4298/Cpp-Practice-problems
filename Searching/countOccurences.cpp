/*
Given a sorted array find number of occurences of particular element, if not present return -1.
I/P : arr[] = {2, 4, 10, 10, 10, 18, 18, 20}
      x = 10
O/P : 3
*/
#include<iostream>
using namespace std;

int findFirstOccurrence(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    int res = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == x)
        {
            res = mid;
            high = mid - 1;
        }
        else if(arr[mid] < x)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return res;
}

int findLastOccurrence(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    int res = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == x)
        {
            res = mid;
            low = mid + 1;
        }
        else if(arr[mid] < x)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return res;
}

int countOccurences(int arr[], int n, int x)
{
    int firstOcc = findFirstOccurrence(arr, n, x);
    int lastOcc = findLastOccurrence(arr, n, x);
    return (lastOcc == -1 && firstOcc==-1)?-1:(lastOcc-firstOcc+1);
}

int main()
{
    int arr[] = {2, 4, 10, 10, 10, 18, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int freq = countOccurences(arr, n, 6);
    cout << freq;
    return 0;
}
