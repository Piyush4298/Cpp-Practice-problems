#include<iostream>
using namespace std;

class Stack{
    int top;
    int cap;
    int *arr;
    public:
        Stack(int c){
            top = -1;
            cap = c;
            arr = new int[cap];
        }

        void push(int x){
            if(top <= cap-1){
                arr[++top] = x;
                cout << x << " pushed into stack\n";
            }else{
                cout << "Stack Overflow\n";
            }
        }

        void pop(){
            if(top < 0){
                cout << "Stack Underflow\n";    
            }
            else{
                int res = arr[top];
                cout << res << " popped out of stack\n";
                top--;
            }
        }
        bool isEmpty(){
            return (top < 0);
        }

        int peek(){
            if(top < 0){
                cout << "Stack Underflow\n";
                return -1;  
            }else{
                return arr[top];
            }
        }

        int size(){
            return top+1;
        }

};

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "peek element before pop: "<< s.peek() << endl;
    s.pop();
    cout << "peek element after pop: "<< s.peek() << endl;
    cout << "Is stack empty? " << (bool)s.isEmpty() << endl;
    cout << "Current stack size is: " << s.size() << endl;
    return 0;
}