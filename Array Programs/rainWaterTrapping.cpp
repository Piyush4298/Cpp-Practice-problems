#include<iostream>
using namespace std;

int rainWaterTrapped(int arr[], int n)
{
    //----max left array----//
    int maxLeft[n];
    maxLeft[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        maxLeft[i] = max(maxLeft[i-1], arr[i]);
    }

    //----max right array----//
    int maxRight[n];
    maxRight[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--)
    {
        maxRight[i] = max(maxRight[i+1], arr[i]);
    }
    
    //--- water trapped values for each building---//
    int water[n];
    for(int i = 0; i < n; i++)
    {
        water[i] = min(maxRight[i], maxLeft[i]) - arr[i];
    }

    //---summation of water trapped---//
    int tot_water = 0;
    for(int x : water)
        tot_water += x;
    return tot_water;
}

int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxWater = rainWaterTrapped(arr, n);
    cout << "Total water trapped is : " << maxWater;
    return 0;
}