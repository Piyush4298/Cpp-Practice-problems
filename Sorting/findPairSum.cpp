/*
Given a sorted array and a sum, find pairs with given sum.

i/p:
arr[] = {2, 3, 8, 11, 13, 15, 22, 24}
sum = 28

o/p : Pair is present
*/
#include<iostream>
using namespace std;

bool findPairSum(int arr[], int n, int sum)
{
    int left = 0, right = n-1;
    while(left < right)
    {
        if(arr[left] + arr[right] == sum)
        {
            return true;
        }
        else if(arr[left] + arr[right] < sum)
            left++;
        else
            right--;
    }
    return false;
}

int main()
{
    int arr[] = {2, 3, 8, 11, 13, 15, 22, 24};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 28;
    
    if(findPairSum(arr, n, sum))
        cout << "Pair is present";
    else
        cout << "Pair is not present !";
    return 0;
}