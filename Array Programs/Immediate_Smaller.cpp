#include<iostream>
using namespace std;

int immediate_smaller(int arr[], int n, int x){
    int smaller  = -1;
    for(int i=0; i<n; i++){
        if(arr[i] < x && arr[i] > smaller)
            smaller = arr[i];
    }
    return smaller;
}
int main(){
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: "<<endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter element x : ";
    cin >> x;
    cout << "element immdiate smaller than x is: " << immediate_smaller(arr, n, x);
    return 0;
}