#include<iostream>
using namespace std;

void reversed(int arr[], int n){
    int low = 0, high = n-1;
    while(low < high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

}
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: "<<endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    reversed(arr, n);
    return 0;
}