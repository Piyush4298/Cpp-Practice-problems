#include<iostream>
using namespace std;

int floorOfElement(int arr[], int n, int x)
{
    int res = -1, low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
            return arr[mid];
        else if(arr[mid] < x){
            res = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return arr[res];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << floorOfElement(arr, n, 20);
    return 0;
}