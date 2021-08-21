#include<iostream>
using namespace std;
typedef long long int lli;

int main()
{
    lli l, r;
    cin >> l >> r;
    cout << "YES\n";
    for(lli i = l; i < r + 1; i+=2)
    {
        cout << i << " " << i+1 << "\n";
    }
    return 0;
}