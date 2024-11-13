

/*

leetcode 60 -> https://leetcode.com/problems/permutation-sequence/description/
https://takeuforward.org/data-structure/find-k-th-permutation-sequence/

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.



Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"

*/

#include <bits/stdc++.h>
using namespace std;

void permutationHelper(string &s, int index, vector<string> &res)
{
    if (index == s.size())
    {
        res.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
    }
}

string BruteForce(int n, int k)
{
    string s;
    vector<string> res;

    for (int i = 1; i <= n; i++)
    {
        s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    // sort the generated permutations
    sort(res.begin(), res.end());
    // make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;

    // TC O(N! * N) +O(N! Log N!)
    // SC O(N)
}

// Optimal and without recursion
string Optimal(int n, int k)
{
    int fact = 1;
    vector<int> num;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        num.push_back(i);
    }
    num.push_back(n);
    string ans;
    k--;
    while (true)
    {
        ans += to_string(num[k / fact]);
        num.erase(num.begin() + k / fact);
        if (num.size() == 0)
            break;
        k %= fact;
        fact /= num.size();
    }
    return ans;

    // TC O(N^2)
    // SC O(N)
}

int main()
{
    int n = 3, k = 3;
    string ans = BruteForce(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    string answ = Optimal(n, k);
    cout << "The Kth permutation sequence is " << answ << endl;

    return 0;
}