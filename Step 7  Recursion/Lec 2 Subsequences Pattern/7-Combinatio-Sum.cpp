/*
Combination Sum - 1


57

2
Problem Statement:

Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Examples:

Example 1:

Input: array = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.


Example 2:

Input: array = [2], target = 1

Output: []

Explaination: No combination is possible.
*/

#include <bits/stdc++.h>

using namespace std;

void Solve(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp)
{
    if (ind == arr.size())
    {
        if (target == 0)
            ans.push_back(temp);

        return;
    }

    if (arr[ind] <= target)
    {
        temp.push_back(arr[ind]);
        Solve(ind, target - arr[ind], arr, ans, temp);
        temp.pop_back();
    }

    Solve(ind + 1, target, arr, ans, temp);
}

vector<vector<int>> combinationSum(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    Solve(0, target, arr, ans, temp);
    return ans;

    // Time Complexity: O(2^t * k) where t is the target, k is the average length
    // Space Complexity: O(k*x), k is the average length and x is the no. of combinations
}

void backtraking(int target, int start,int n,vector<int> &path,vector<int> &nums,vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(path);
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (nums[i] > target)
            continue;   
        path.push_back(nums[i]);
        backtraking(target - nums[i], i, n, path, nums, ans);
        path.pop_back();
    }
}
vector<vector<int>> combinationSumOptimal(vector<int> &candidates, int target)
{

    vector<int> nums, path;
    vector<vector<int>> ans;
    nums = candidates;
    int n = nums.size();
    backtraking(target, 0, n, path, nums, ans);
    return ans;
}

int main()
{
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    ans = combinationSumOptimal(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
