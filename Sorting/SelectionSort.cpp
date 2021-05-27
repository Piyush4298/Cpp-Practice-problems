#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i < n-1; i++){
        int min_index = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
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
    selectionSort(arr, n);

    cout << "\nArray after sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}