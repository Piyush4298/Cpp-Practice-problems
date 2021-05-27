/*In this problem we have to sort the char arr in accordance to integer array
as every integer is related with a character*/
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

void sort_acc_to_other(int a[], char b[], int n)
{
    pair<int, char> p[n];
    for(int i = 0; i < n; i++)
        p[i] = {a[i], b[i]};
    sort(p, p+n);
    for(int i = 0; i<n; i++)
        cout << p[i].second << " ";
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    char b[n];
    for(int i = 0; i<n; i++)
        cin >> a[i];
    for(int i = 0; i<n; i++)
        cin >> b[i];
    sort_acc_to_other(a, b, n);
    return 0;
}