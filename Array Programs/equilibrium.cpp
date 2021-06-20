/*
Given an array arr of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
Input:  n = 5
        A[] = {1, 3, 5, 2, 2}
Output: 3   ---------->(index+1)

point.
*/

#include<iostream>
using namespace std;

int findEqbm(int arr[], int n)
{
    if(n == 1)
        return 1;
    for(int i = 1; i < n; i++)
        arr[i] += arr[i-1];
    for(int i = 1; i < n; i++)
    {
        if(arr[i-1] == (arr[n-1]-arr[i]))
            return i+1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Equilibrium is at position : " << findEqbm(arr, n);
}