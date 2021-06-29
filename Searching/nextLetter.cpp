#include<iostream>
using namespace std;

char nextAlphabet(char arr[], int n, char x)
{
    char res = '#' ;
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == x)
            return arr[mid+1];
        else if(arr[mid] < x)
            low = mid + 1;
        else{
            res = arr[mid];
            high = mid - 1;
        }
        
    }
    return res;
}

int main()
{
    char arr[] = {'a', 'c', 'f', 'h', 'j', 'o', 'x', 'y'};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Next alphabet: " << nextAlphabet(arr, n, 'y'); 
    return 0;
}