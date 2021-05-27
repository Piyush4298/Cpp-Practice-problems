#include<iostream>
using namespace std;

int log_base2(int n){
    if(n == 1)
        return 0;
    else
        return 1 + log_base2(n/2);
}

int main(){
    cout << log_base2(16);
    // for n = 16 we get ans 4
    // for n = 8 we get ans 3
    return 0;
}