/*

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.



Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int minV = INT_MAX;
            for (int k = i; k <= j; k++)
                minV = min(minV, arr[k]);

            sum += minV;
        }
    }
    return sum;

    // TC O(N^3)
}
int Better(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int minV = INT_MAX;
        for (int j = i; j < arr.size(); j++)
        {
            minV = min(minV, arr[j]);
            sum += minV;
        }
    }
    return sum;

    // TC O(N^2)
}

vector<int> findNse(vector<int> arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            nge[i] = n;
        else
            nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPse(vector<int> arr)
{
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        if (!st.empty())
            pse[i] = st.top();
        st.push(i);
    }
    return pse;
}

int Optimal(vector<int> arr)
{
    int n = arr.size();
    vector<int> nse = findNse(arr);
    vector<int> pse = findPse(arr);
    int total = 0;
    int MOD = (int)(1e9 + 7);

    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nge[i] - i;
        total += (left * right * 1ll * arr[i]) % MOD;
        cout << i << " " << total << " " << left << " " << right << endl;
        total %= MOD;
    }
    return total;

    // TC O(5N)
    // SC O(5N)
}

int main()
{
    vector<int> vec = {3, 1, 2, 4};
    cout << BruteForce(vec) << endl;
    cout << Better(vec) << endl;
    cout << Optimal(vec) << endl;

    return 0;
}