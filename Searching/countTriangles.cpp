/*Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

i/p : arr[] = {4,2,3,4}
o/p : 4
*/

#include<iostream>
#include<algorithm>
using namespace std;
int countTriangles(int arr[], int n) {
        sort(arr, arr+n);
        int count = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int l = 0;
            int r = i-1;
            while(l < r)
            {
                if(arr[l] + arr[r] > arr[i])
                {
                    count += (r-l);
                    r--;
                }
                else
                    l++;
            }
        }
        return count;
    }
int main()
{
    int arr[] = {4,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Number of triangles possible: " << countTriangles(arr, n);
    return 0;
}