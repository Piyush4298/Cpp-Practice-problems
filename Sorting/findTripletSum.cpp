/*
Given a sorted array and a sum, find pairs with given sum.

i/p:
arr[] = {1, 4, 6, 8, 10, 45}
sum = 22

o/p : 4 8 10
      Triplet is present
*/
#include<iostream>
using namespace std;

bool findTripletSum(int arr[], int n, int sum)
{
    int l, r;
    for(int i = 0; i < n-2; i++)
    {
        l = i+1;
        r = n-1;
        while(l < r)
        {
            if(arr[i] + arr[l] + arr[r] == sum)
            {
                cout << arr[i] << " " <<arr[l] << " " <<arr[r] << endl;
                return true;
            }
            else if(arr[i] + arr[l] + arr[r] < sum)
                l++;
            else
                r--;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 6, 8, 10, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 22;
    
    if(findTripletSum(arr, n, sum))
        cout << "Triplet is present";
    else
        cout << "Triplet is not present !";
    return 0;
}