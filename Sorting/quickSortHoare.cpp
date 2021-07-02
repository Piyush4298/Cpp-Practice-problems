#include<iostream>
using namespace std;

int hoaresPartition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h+1;
    while(true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if(i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int p = hoaresPartition(arr, l, h);
        quickSort(arr, l, p);
        quickSort(arr, p+1, h);
    }
}

int main()
{
    int arr[] = {3, 5, 8, 10, 9, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Quick Sort using hoare's partition: ";
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}