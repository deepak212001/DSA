/*
Power Set: Print all the possible subsequences of the String


58

1
Problem Statement: Given a string, find all the possible subsequences of the string.

Examples:

Example 1:
Input: arr=[1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

*/

#include <bits/stdc++.h>
using namespace std;

void solveAllPos(int ind, vector<int> &ds, vector<int> arr, int n)
{
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }
    // take and pick the particular index into the subsequences
    ds.push_back(arr[ind]);
    solveAllPos(ind + 1, ds, arr, n);
    ds.pop_back();

    // not pick or not take condition  , this element arwe not add to subsequence

    solveAllPos(ind + 1, ds, arr, n);
}

void solveSum(int ind, vector<int> &ds, int s, int sum, vector<int> arr, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    // take and pick the particular index into the subsequences
    ds.push_back(arr[ind]);
    s += arr[ind];
    solveSum(ind + 1, ds, s, sum, arr, n);
    s -= arr[ind];
    ds.pop_back();

    // not pick or not take condition  , this element arwe not add to subsequence

    solveSum(ind + 1, ds, s, sum, arr, n);
}

vector<vector<int>> subset(vector<int> arr, int n)
{
    vector<vector<int>> ans;
    int s = 1 << n;
    for (int i = 0; i < s; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                temp.push_back(arr[j]);
        }
        ans.push_back(temp);
    }
    return ans;

    // TC O(N*2^N)
    // SC O(1)
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ds;
    int n = 3;
    cout << "All possible subsequences are: " << endl;
    solveAllPos(0, ds, arr, n);

    cout << "sum" << endl;
    // solveSum(0, ds, 0, 2, arr, n);

    vector<vector<int>> result = subset(arr, n);

    for (auto it : result)
    {
        for (auto its : it)
            cout << its << " ";

        cout << endl;
    }
}