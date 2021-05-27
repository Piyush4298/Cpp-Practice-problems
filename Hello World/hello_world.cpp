#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    int num;
    num = 10;
    cout << "Hello World the number is: " << num <<endl;
    cout << "This is the vector's 1st element: " << v[0];
    return 0;
}