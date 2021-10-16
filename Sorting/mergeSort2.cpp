#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int marr[high+1];
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            marr[k] = arr[i];
            k++, i++;
        }
        else
        {
            marr[k] = arr[j];
            k++, j++;
        }
    }

    while(i <= mid)
    {
        marr[k] = arr[i];
        k++, i++;
    }

    while(j <= high)
    {
        marr[k] = arr[j];
        k++, j++;
    }

    for(int idx = low; idx <= high; idx++)
    {
        arr[idx] = marr[idx];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {11, 20, 40, 12, 10, 9, 53, 8888};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}