#include<iostream>
using namespace std;

// int countSetBits(int n)
// {
//     int count = 0;
//     while(n > 0)
//     {
//         if(n % 2 == 1)
//             count++;
//         n = n/2;
//     }
//     return count;
// }

int brian_kerningam(int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n = n & (n-1);
    }
    return count;
}

int main()
{
    int n = 10;
    cout << "Count of set bits: " << brian_kerningam(n);
    return 0;
}