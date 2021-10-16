#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

void funcEven(int num)
{
    for(int i = 0; i < num; i++)
    {
        if(i%2 == 0)
            cout << "Even\n"; 
            //cout << "Thread is working -> Printing Even"<< endl;
    }
}

void funcOdd(int num)
{
    for(int i = 0; i < num; i++)
    {
        if(i%2 != 0)
            cout << "Odd\n";
            //cout << "Thread is working -> Printing odd" << endl;
    }
}

int main()
{
    auto startTime = high_resolution_clock::now();

    thread t1(funcEven, 10000);
    thread t2(funcOdd, 10000);

    t1.join();
    t2.join();
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << "Total time : " << duration.count()/1000000;
    return 0;
}