#include<iostream>
using namespace std;

void print1toN(int n)
{
    if(n == 1)
    {
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    print1toN(n-1);
}

int main()
{
    int n = 6;
    print1toN(n);
    return 0;
}