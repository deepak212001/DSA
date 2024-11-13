/*

Postfix to Prefix Conversion

You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

Example 1:

Input:
ABC/-AK/L-*
Output:
*-A/BC-/AKL
Explanation:
The above output is its valid prefix form.

*/

#include <bits/stdc++.h>

using namespace std;

void PostfixTOPrefix(string s)
{

    stack<string> st;
    string result = "";
    int n = s.size();
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
            result = c + t2 + t1;
            st.push(result);
        }
    }
    cout << "Prefix expression: " << result << endl;
}

int main()
{
    string exp = "pq+mn-*";
    cout << "Postfix expression: " << exp << endl;
    PostfixTOPrefix(exp);
    return 0;
}