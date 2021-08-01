#include<iostream>
using namespace std;

class Queue
{
    int size, cap, front;
    int *arr;
    public:
    
    Queue(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }

    void enqueue(int x)
    {
        if(isFull())
            return;
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if(isEmpty())
            return;
        front = (front+1)%cap;
        size--;
    }

    int getFront()
    {
        if(isEmpty())
            return -1;
        return front;
    }

    int getRear()
    {
        if(isEmpty())
            return -1;
        return (front+size-1)%cap;
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
    cout << "Current size: " << q.currSize();

    return 0;
}