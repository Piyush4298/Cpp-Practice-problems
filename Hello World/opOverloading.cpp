#include<iostream>
using namespace std;

class Complex
{
private:
    int a, b;
public:
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    Complex operator +(Complex temp)
    {
        Complex c3(0, 0);
        c3.a = a + temp.a;
        c3.b = b + temp.b;
        return c3;
    }

    string print()
    {
        string s = to_string(a) + " + i" + to_string(b);
        return s;
    }
};

int main()
{
    Complex c1(3, 4), c2(5, 6);
    Complex c3 = c1 + c2;
    cout << c3.print();
    return 0;
}