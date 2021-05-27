/*
Given a binary sorted array in non-increasing order of 0s and 1s. Find count of ones.
i/p : n = 8
      arr[] = {1, 1, 1, 1, 1, 0, 0, 0}
o/p : 5
*/
#include<iostream>
using namespace std;

int countOnes(int arr[], int n){
    int low = 0, high = n-1;
    while(high >= low){
        int mid = low + (high-low)/2;
        if(((mid==high) || arr[mid+1]==0) && (arr[mid]==1))
            return mid+1;
        else if(arr[mid] == 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: " << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "No of ones: " << countOnes(arr, n);
    return 0;
}