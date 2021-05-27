#include<iostream>
#include<forward_list>
using namespace std;

int main(){
    forward_list<int> f1 = {10, 15, 20, 25};
    f1.push_front(5);
    f1.push_front(10);
    f1.push_front(20);
    f1.pop_front();
    cout << "f1 : ";
    for(auto x : f1)
        cout << x << " ";
    cout << endl;
    f1.remove(10);
    for(auto it = f1.begin(); it != f1.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "---------------------------------------------------------\n";
    forward_list<int> f2;
    f2.assign(5, 10);
    cout << "f2 : ";
    for(auto x : f2)
        cout << x << " ";
    cout << endl;
    cout << "---------------------------------------------------------\n";
    forward_list<int> f3 = {5, 20, 30};
    auto it = f3.insert_after(f3.begin(), 10);
    it = f3.insert_after(it, {40, 45, 50});
    cout << "f3 : ";
    for(auto x : f3)
        cout << x << " ";
    cout << endl;
    it = f3.emplace_after(it, 60);
    for(auto x : f3)
        cout << x << " ";
    cout << endl;
    it = f3.erase_after(it);
    for(auto x : f3)
        cout << x << " ";
    cout << endl;
    return 0; 
}