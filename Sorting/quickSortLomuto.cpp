#include<iostream>
using namespace std;

int lomutoPartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l-1;
    for(int j = l; j < h; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return i+1;
}

void quickSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int p = lomutoPartition(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

int main()
{
    int arr[] = {8, 4, 7, 9, 5, 10, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Quick Sort using lomuto partition: ";
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
