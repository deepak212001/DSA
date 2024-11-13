/*
Prefix to Postfix Conversion

You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Example:

Input:
*-A/BC-/AKL
Output:
ABC/-AK/L-*
Explanation:
The above output is its valid postfix form.

*/

#include <bits/stdc++.h>

using namespace std;

void PrefixTOinfix(string s)
{
    stack<string> st;
    string result = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            st.push(string(1, c));
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            result = t1 + t2 + c;
            st.push(result);
        }
    }
    cout << "Postfix expression: " << result << endl;

    // TC O(N)
    // SC O(N)
}

int main()
{
    string exp = "*+pq-mn";
    cout << "Prefix expression: " << exp << endl;
    PrefixTOinfix(exp);
    return 0;
}