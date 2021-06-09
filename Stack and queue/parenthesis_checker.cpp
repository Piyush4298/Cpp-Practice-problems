#include<iostream>
#include<stack>
using namespace std;

bool isBalancedParenthesis(string &s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if(s[i] == '}')
        {
            if(!s.empty() && st.top() == '{')
                st.pop();
            else
                return false;
        }
        else if(s[i] == ']')
        {
            if(!s.empty() && st.top() == '[')
                st.pop();
            else
                return false;
        }
        else if(s[i] == ')')
        {
            if(!s.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cout << "Enter brackets : ";
    cin >> s;

    if(isBalancedParenthesis(s))
        cout << "balanced" << endl;
    else
        cout << "not balanced" << endl;
    return 0;
}