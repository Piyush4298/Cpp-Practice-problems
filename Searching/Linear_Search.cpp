#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int x){
    for(int i = 0; i<n; i++){
        if(arr[i] == x)
            return (i+1);
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
    cout << "Element is present at position: " << linear_search(arr, n, x);
    // If element is not present in given array then function returns -1.
    return 0;
}