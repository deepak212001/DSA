/*

Prefix to Infix Conversion


You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.

Example 1:

Input:
*-A/BC-/AKL
Output:
((A-(B/C))*((A/K)-L))
Explanation:
The above output is its valid infix form.


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
            result = '(' + t1 + c + t2 + ')';
            st.push(result);
        }
    }
    cout << "Infix expression: " << result << endl;

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