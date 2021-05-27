#include<iostream>
using namespace std;

int secondLargestEle(int arr[], int n){
    int res = -1, largest = 0;
    for(int i=1; i<n ; i++){
        if(arr[i] > arr[largest]){
            res = largest; 
            largest = i;
        }
        else if(arr[i] != arr[largest]){
            if(res == -1 || arr[i] > arr[res])
                res = i;
        }
    }
    return arr[res];
    
}


int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: "<<endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Second Largest element: " << secondLargestEle(arr, n);
    return 0;
}