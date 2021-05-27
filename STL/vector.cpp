/*Given a vector V of n elements. Return the vector containing prime numbers that are at prime index(1-indexing).
Example:
Input:
5
3 5 2 4 8
Output:
5 2
Explanation:
Only 5 and 2 are the numbers that are prime and are present at prime position (2 and 3 respectively).
*/
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

vector<int> primeAtPrime(vector<int> &v){
    vector<int> p;
    for(int i = 0; i < v.size(); i++){
        if(isPrime(v[i])){
            if(isPrime(i+1)){
                p.push_back(v[i]);
            }
        }
    }
    return p;
}
int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        v.push_back(m);
    }
    vector<int> res_vec = primeAtPrime(v);
    for(auto x : res_vec)
        cout << x << " "; 
    return 0;                                   
}