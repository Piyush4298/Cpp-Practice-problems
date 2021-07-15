#include<iostream>
using namespace std;

// int countBits(int arr[], int n)
// {
//     int count = 0;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             int res = 0;
//             int val = arr[i] ^ arr[j];
//             while(val > 0)
//             {
//                 val = (val & (val-1));
//                 res++; 
//             }
//             count = count + res;
//         }
//     }
//     return count;
// }

int countBits(int arr[], int n)
{
    int ans = 0;
    for(int i = 0; i < 32; i++)
    {
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if((arr[j] & (1 << i)) != 0)
                count++;
        }
        ans += count * (n-count) * 2;
    }
    return ans;
}
int main()
{
    int arr[] = {23, 25, 21, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countBits(arr, n);
    return 0;
}