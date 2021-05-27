/*
Moore's Voting Algorithm
Task is to find majority element in array.
Majority element is when count(element) > size/2
*/
#include<iostream>
using namespace std;

int findCandidate(int arr[], int n){
    int maj_index = 0, count = 1;
    for(int i=1; i<n; i++){
        if(arr[maj_index] == arr[i])
            count++;
        else
            count--;
        if(count == 0){
            maj_index = i;
            count = 1;
        }
    }
    return arr[maj_index];
}

bool isMajority(int arr[], int n, int cand){
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == cand)
            count++;
    }
    if(count > n/2)
        return 1;
    else
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
    int cand = findCandidate(arr, n);
    if(isMajority(arr, n, cand))
        cout << "Majority element is: " << cand << endl;
    else
        cout << "No majority element" << endl;
}