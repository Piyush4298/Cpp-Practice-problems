/*
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1? 
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/
#include<iostream>
#include<queue>
using namespace std;

// bool areRotation(string s1, string s2)
// {
//     if(s1.size() != s2.size())
//         return false;
//     string s3 = s1 + s1;

//     if(s3.find(s2) != string::npos)
//         return true;
//     return false;
// }

bool areRotation(string s1, string s2)
{
    if(s1.size() != s2.size())
        return false;
    queue<char> q1, q2;
    for(int i = 0; i < s1.size(); i++)
        q1.push(s1[i]);
    for(int i = 0; i < s2.size(); i++)
        q2.push(s2[i]);

    int s = s1.size();
    while(s--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if(q1 == q2)
            return true;
    }
    return false;
}

int main()
{
    string s1 = "ABCD", s2 = "CDAB";
    if(areRotation(s1, s2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
