#include<iostream>
using namespace std;

class Guy
{
private:
    int a, b;
public:
    void setData(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    friend void fun(Guy);
};

void fun(Guy g)
{
    cout << "Sum of friend: " << g.a + g.b;
}

int main()
{
    Guy g1;
    g1.setData(10, 20);
    fun(g1);
    return 0;
}