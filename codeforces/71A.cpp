#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string word;
        cin >> word;
        int l = word.length();
        if(l <= 10)
        {
            cout << word;
            continue;
        }
        else
        {
            cout << word[0] << l-2 << word[l-1];
            continue;
        }
    }   
    return 0;
}