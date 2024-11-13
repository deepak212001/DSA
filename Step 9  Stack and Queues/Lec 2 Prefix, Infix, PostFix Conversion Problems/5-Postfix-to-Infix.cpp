/*
Postfix to Infix Conversion
Difficulty: MediumAccuracy: 49.41%Submissions: 24K+Points: 4
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

Example:

Input:
ab*c+
Output:
((a*b)+c)
Explanation:
The above output is its valid infix form.
*/

#include <bits/stdc++.h>

using namespace std;

void PostfixTOinfix(string s)
{

    stack<string> st;
    string result = "";

    for (auto c : s)
    {

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            st.push(string(1, c));
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            result = '(' + t2 + c + t1 + ')';
            st.push(result);
        }
    }
    cout<<st.size()<<endl;
    cout << "Infix expression: " << st.top() << endl;

    // TC O(N)
    // SC O(N)
}

int main()
{
    string exp = "pq+mn-*";
    cout << "Postfix expression: " << exp << endl;
    PostfixTOinfix(exp);
    return 0;
}