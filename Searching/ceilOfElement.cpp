#include<iostream>
using namespace std;

int ceilOfElement(int arr[], int n, int x)
{
    int res = -1, low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
            return arr[mid];
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            res = mid;
            high = mid - 1;
        }
    }
    return arr[res];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << ceilOfElement(arr, n, 11);
    return 0;
}