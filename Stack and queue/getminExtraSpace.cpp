#include<iostream>
#include<stack>
using namespace std;

class Stack_two
{
    stack<int> st;
    stack<int> ss;

    public:
        void push(int a)
        {
            st.push(a);
            cout << "Pushed -> " << a << endl;
            if(ss.size() == 0 || a <= ss.top())
                ss.push(a);
            return;
        }

        void pop()
        {
            if(st.empty()){
                cout << "Underflow\n";
                return;
            }    
            int ans = st.top();
            st.pop();
            if(ss.top() == ans)
            {
                ss.pop();
            }
            cout << "Popped -> " << ans << endl;
            return;
        }

        int getMin()
        {
            if(ss.size()==0)
                return 0;
            return ss.top();
        }

};

int main()
{
    Stack_two s;
    
    s.push(18);
    s.push(19);
    cout << "Current minimum : " << s.getMin() << endl;
    s.push(29);
    s.push(15);
    cout << "Current minimum : " << s.getMin() << endl;
    s.push(16);
    s.pop();
    cout << "Current minimum : " << s.getMin() << endl;
    s.pop();
    s.pop();
    cout << "Current minimum : " << s.getMin() << endl;
    return 0;
}