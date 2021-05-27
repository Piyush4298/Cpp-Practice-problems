#include<iostream>
using namespace std;

void left_rotate_by_one(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i<n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
    cout << "Array after one rotation: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: "<<endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Array before rotation: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<"\n";
    left_rotate_by_one(arr, n);
    return 0;
}