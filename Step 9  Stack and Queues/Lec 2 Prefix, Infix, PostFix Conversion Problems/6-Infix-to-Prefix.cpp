/*
Infix to Prefix


Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a prefix expression.

Examples:

Example 1:
Input: x+y*z/w+u
Output: ++x/*yzwu
Explanation: Infix to prefix

Example 2:
Input: a+b
Output: +ab
Explanation: Infix to prefix



infix expression
reverse infix expression
infix to postfix
reverse returned postfix expression

*/

#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
string infixToPerfix(string s)
{
    reverse(s.begin(), s.end());
    // Replace ( with ) and vice versa
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
            i++;
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
            i++;
        }
    }


    string res = "";
    stack<char> st;
    for (auto c : s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            res += c;

        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(c) <= prec(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout << res;

    // TC O(N)
    // SC O(N)
}

int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixToPerfix(exp);
    return 0;
}