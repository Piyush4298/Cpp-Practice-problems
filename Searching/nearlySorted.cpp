#include<iostream>
using namespace std;

int searchInNearlySorted(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid + 1] == x)
            return mid + 1;
        else if(arr[mid - 1] == x)
            return mid - 1;
        else if(arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 30, 20, 50, 40, 60, 70, 90, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = searchInNearlySorted(arr, n, 30);
    cout << res;
    return 0;
}