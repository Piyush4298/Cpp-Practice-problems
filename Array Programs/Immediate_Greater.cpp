#include<iostream>
using namespace std;

int immediate_greater(int arr[], int n, int x){
    int diff  = INT_MAX;
    int ans = -1;
    for(int i=0; i<n; i++){
        if((arr[i]-x)>0  && (arr[i]-x)<diff){
            ans = arr[i];
            diff = arr[i] - x;
        }
    }
    return ans;
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
    cout << "element immdiate greater than x is: " << immediate_greater(arr, n, x);
    return 0;
}