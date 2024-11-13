/*


796. Rotate String


Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false

*/


#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) 
{
    if(s.size()!=goal.size())
        return false;        
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        s+=s[i];
        string sub=s.substr(i+1,len+1);
        if(sub==goal)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string str1 = "AACD", str2 = "ACDA";

    if (rotateString(str1, str2))
        cout<<"Strings are rotations of each other";
    else
        cout<<"Strings are not rotations of each other";
    return 0;
}  