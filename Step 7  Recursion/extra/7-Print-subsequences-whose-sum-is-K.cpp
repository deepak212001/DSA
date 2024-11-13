/*
Power Set: Print all the possible subsequences of the String


58

1
Problem Statement: Given a string, find all the possible subsequences of the string.

Examples:

Example 1:
Input: arr=[1,2,3], k=3
Output: [[1,2],[3]]

*/

#include <bits/stdc++.h>
using namespace std;

void solveSum(int ind, vector<int> &ds, int s, int sum, vector<int> arr, int n)
{
    if (s <= sum)
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
}

vector<vector<int>> subset(vector<int> arr, int n, int sum)
{
    vector<vector<int>> ans;
    int s = 1 << n; // that means pow(2,n)
    for (int i = 0; i < s; i++)
    {
        int add = 0;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                add += arr[j];
                temp.push_back(arr[j]);
            }
        }
        if (add == sum)
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
    int sum;
    cin >> sum;
    int n = arr.size();
    cout << "All possible subsequences whose sum is K f : " << endl;
    solveSum(0, ds, 0, sum, arr, n);

    vector<vector<int>> result = subset(arr, n, sum);
    cout << "\nAll possible subsequences whose sum is K : " << endl;
    for (auto it : result)
    {
        for (auto its : it)
            cout << its << " ";

        cout << endl;
    }
}