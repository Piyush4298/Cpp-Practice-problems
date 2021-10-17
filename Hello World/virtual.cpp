#include<iostream>
using namespace std;

class Car
{
public:
    Car()
    {
        cout << "Car class initialised!\n";
    }
    virtual void changeGear()
    {
        cout << "Changing Gear from Car class\n";
    }
};

class SportsCar : public Car
{
public:
    SportsCar()
    {
        cout << "SportsCar class initialised!\n";
    }
    void changeGear()
    {
        cout << "Changing Gear from SportsCar class\n";
    } 
};

int main()
{
    Car *cp;
    SportsCar obj;
    cp = &obj;
    cp->changeGear();
    return 0;
}