#include<iostream>
using namespace std;

int binary_search_ele(int arr[], int n, int x){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            high = mid - 1;
        else if(arr[mid] < x)
            low = mid + 1;
    }
    return -1;
}

int main(){
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: " << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter element to be searched: ";
    cin >> x;
    cout << "Element is present at position: " << binary_search_ele(arr, n, x);
    // If element is not present in given array then function returns -1.
    return 0;
}