#include<iostream>
#include<stack>
using namespace std;

class Stack_two
{
    stack<int> st;
    int minEle;
    public:
        void push(int a)
        {
            if(st.empty())
            {
                st.push(a);
                minEle = a;
            }
            else
            {
                if(a >= minEle)
                    st.push(a);
                else if(a < minEle)
                {
                    st.push(2*a - minEle);
                    minEle = a;
                }
            }
            cout << "Pushed -> " << a << endl;
        }

        void pop()
        {
            int ans;
            if(st.empty())
                return;
            else
            {
                if(st.top() >= minEle)
                {
                    ans = st.top();
                    st.pop();
                }
                else if(st.top() < minEle)
                {
                    ans = minEle;
                    minEle = 2*minEle - st.top();
                    st.pop();
                }
            }
            cout << "Popped -> " << ans << endl;
        }

        int getMin()
        {
            if(st.empty())
                return -1;
            return minEle;
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