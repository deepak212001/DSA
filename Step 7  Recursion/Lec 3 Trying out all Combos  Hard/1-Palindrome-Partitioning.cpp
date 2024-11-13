/*
Given a string s, partition s such that every
substring
 of the partition is a
palindrome
. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]

*/

#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (s[start++] != s[end--])
        return false;
    return true;
}
void partitionHelper(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            partitionHelper(index + 1, s, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    partitionHelper(0, s, path, res);
    return res;

    // TC   O( (2^n) *k*(n/2) )    where k  is the average length of the palindrome list.
    // SC  O(k * x)     x such list of palindromes in our final answer
}

int main()
{
    string s = "aabb";
    vector<vector<string>> ans = partition(s);
    int n = ans.size();
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto i : ans)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}