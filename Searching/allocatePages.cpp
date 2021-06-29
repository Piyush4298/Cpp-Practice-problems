#include<iostream>
using namespace std;

bool isvalid(int arr[], int n, int k, int mx)
{
    int student = 1;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum > mx){
            student++;
            sum = arr[i];
        }
        if(student > k)
            return false;
    }
    return true;
}

int minAllocation(int arr[], int n, int k)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    int low = 0, high = sum;
    int res = -1;

    if(n < k)
        return res;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if (isvalid(arr, n, k, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int students = 2;
    cout << "Minimized allocation for max books alloted: " << minAllocation(arr, n, students);
    return 0;
}