#include<iostream>
using namespace std;

int findFirstOccurrence(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    int res = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == x && (mid == 0 || arr[mid-1] < x))
        {
            return mid;
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
        if(arr[mid] == x && (mid == n-1 ||arr[mid+1]>x))
        {
            return mid;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return res;
}

int main()
{
    int arr[] = {10, 10, 10, 10, 10, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pos1 = findFirstOccurrence(arr, n, 10);
    int pos2 = findLastOccurrence(arr, n, 10);
    cout << "First occurrence : " << pos1 << endl;
    cout << "Last occurrence : " << pos2 << endl;
    return 0;
}