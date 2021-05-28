#include<iostream>
using namespace std;

int findUniqueEle(int arr[], int n)
{
    int l = 0, h = n-1;
    if(arr[l] != arr[l + 1])
        return arr[l];
    else if(arr[h] != arr[h-1])
        return arr[h];
    while(l <= h)
    {
        int mid = l + (h-l)/2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1])
            return arr[mid];
        else if((mid % 2 == 0 && arr[mid] == arr[mid+1]) || (mid % 2 != 0 && arr[mid] == arr[mid-1]))
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = findUniqueEle(arr, n);
    if(ele == -1)
        cout << "No such element\n";
    else
        cout << "Unique element is : " << ele;
    return 0;
}