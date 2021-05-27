#include<iostream>
using namespace std;

int bin(int n){
    if(n==0)
        return 0;
    bin(n/2);
    cout << n%2;
}

int main(){
    bin(5);
    return 0;
}