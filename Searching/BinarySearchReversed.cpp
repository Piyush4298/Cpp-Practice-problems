#include<iostream>
using namespace std;

int reversedBinarySearch(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
            return mid+1;
        else if(arr[mid] > x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {7, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = reversedBinarySearch(arr, n, 7);
    if(res == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at position : " << res << endl;
    return 0;
}