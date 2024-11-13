/*


205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

*/

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, char> mp1, mp2;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp1.find(s[i]) != mp1.end())
        {
            if (mp1[s[i]] != t[i])
                return false;
        }
        else if (mp2.find(t[i]) != mp2.end())
        {
            if (mp2[t[i]] != s[i])
                return false;
        }
        else
        {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
    }
    return true;

    // TC O(N)
    // SC O(N)
}
int main()
{
    string s = "aab", t = "xxy";
    cout << isIsomorphic(s, t) << endl;
    return 0;
}