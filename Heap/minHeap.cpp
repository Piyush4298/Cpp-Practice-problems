#include<iostream>
using namespace std;

class MinHeap
{
    int size, capacity;
    int *arr;
public:
    MinHeap(int c){
        size = 0;
        capacity = c;
        arr = new int[capacity];
    }

    int left(int i )
    {
        return 2*i+1;
    }

    int right(int i)
    {
        return 2*i+2;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    void insert(int x);
    void print();
    void heapify(int i);
};

void MinHeap :: insert(int x)
{
    if(size == capacity)
        return;
    size++;
    arr[size-1] = x;
    // for(int i = size - 1; i != 0 && arr[parent(i)] > arr[i]; i = parent(i))
    // {
    //     swap(arr[parent(i)], arr[i]);
    // }
}

void MinHeap :: print()
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void MinHeap :: heapify(int i)
{
    int lt = left(i), rt = right(i);
    int smallest = i;
    if(lt < size && arr[lt] < arr[smallest])
        smallest = lt;
    if(rt < size && arr[rt] < arr[smallest])
        smallest = rt;
    if(smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(smallest);
    }
}


int main()
{
    MinHeap hp(10);
    hp.insert(40);
    hp.insert(20);
    hp.insert(30);
    hp.insert(35);
    hp.insert(25);
    hp.insert(80);
    hp.insert(32);
    hp.insert(100);
    hp.insert(70);
    hp.insert(60);
    hp.heapify(0);
    hp.print();
    return 0;
}