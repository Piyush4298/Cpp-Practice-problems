#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout << "\nArray after sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main(){
    int n; 
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: " << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Array before sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    InsertionSort(arr, n);
    return 0;
}