#include<iostream>
using namespace std;

int searchInSNR(int arr[], int n, int x)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
            return mid;
        if(arr[low] < arr[mid])
        {
            if(arr[low] <= x && arr[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if(arr[high] >= x && arr[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {11, 12, 15, 18, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Element is at: " << searchInSNR(arr, n, 2);
    return 0;
}