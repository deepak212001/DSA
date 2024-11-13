/*

1614. Maximum Nesting Depth of the Parentheses


Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3

*/

#include <bits/stdc++.h>
using namespace std;


int maxDepth(string s) {
    /*
    int n= s.size();
    stack<char> st;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') 
            st.push('(');
        if(s[i]==')') 
            st.pop();
        int l=st.size();
        ans=max(ans,l);
    }
    return ans;
    
    // TC O(N)
    // SC O(N)
    
    */


    int curr=0;
    int ans=0;
    for(auto ch:s)
    {
        if(ch=='(')
        {
            curr++;
            ans=max(curr,ans);
        }
        if(ch==')')
            curr--;
    }
    return ans;

    // TC O(N)
    // SC O(1)
}   

int main()
{
    string s = "( ((X)) (((Y))) )";
    cout << maxDepth(s);
 
    // This code is contributed by rakeshsahni
 
    return 0;
}