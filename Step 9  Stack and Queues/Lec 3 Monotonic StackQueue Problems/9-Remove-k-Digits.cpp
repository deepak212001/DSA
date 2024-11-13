/*

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    if (num.size() <= k)
        return "0";

    string res = "";
    stack<char> st;

    for (char c : num)
    {
        while (!st.empty() && (st.top() - '0') > (c - '0') && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;

    // TC O(3N) + O(K)
    // SC O(N) + O(N)
}

string removeKdigits(string num, int k)
{
    string s = "";
    for (char c : num)
    {
        while (s.size() && s.back() > c && k)
        {
            k--;
            s.pop_back();
        }
        if (s.size() || c != '0')
            s.push_back(c);
    }
    while (s.size() && k--)
        s.pop_back();
    return (s.size() == 0) ? "0" : s;
}

int main()
{
    string str = "1432219";
    int k = 3;

    string result = removeKdigits(str, k);

    // Output the result
    if (result.empty())
    {
        cout << "0\n";
    }
    else
    {
        cout << result << "\n";
    }

    return 0;
}