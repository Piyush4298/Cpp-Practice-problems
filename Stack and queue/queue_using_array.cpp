#include<iostream>
using namespace std;

class Queue
{
    int size, cap;
    int *arr;
    public:
    
    Queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }

    void enqueue(int x)
    {
        if(isFull())
            return;
        arr[size++] = x;
    }

    void dequeue()
    {
        if(isEmpty())
            return;
        for(int i = 0; i < size-1; i++)
            arr[i] = arr[i+1];
        size--;
    }

    int getFront()
    {
        if(isEmpty())
            return -1;
        return 0;
    }

    int getRear()
    {
        if(isEmpty())
            return -1;
        return size-1;
    }

    bool isFull()
    {
        return size==cap;
    }

    bool isEmpty()
    {
        return size==0;
    }

    int currSize()
    {
        return size;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    cout << "Current Size: " << q.currSize() << endl;
    q.dequeue();
    cout << "Is queue empty? " << (q.isEmpty()==1?"Yes":"No") << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    cout << "Is queue full? " << (q.isFull()==1?"Yes":"No") << endl;
    cout << "front item is: " << q.getFront() << endl;
    cout << "rear item is: " << q.getRear() << endl;
    return 0;
}