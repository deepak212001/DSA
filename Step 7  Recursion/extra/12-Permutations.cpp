/*

leetcode 46 -> https://leetcode.com/problems/permutations/description/
https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
*/

#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> sum)
{
    cout << endl;
    cout << "All Permutations are " << endl;
    cout << "[ \n";
    for (int i = 0; i < sum.size(); i++)
    {
        cout << "  [ ";
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << "]";
        cout << endl;
    }
    cout << "]";
}

void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
    // Time Complexity:  N! x N
    // Space Complexity:  O(N!)
}

//  Backtracking
void BackPermute(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        BackPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permuteBacktracking(vector<int> &nums)
{
    vector<vector<int>> ans;
    BackPermute(0, nums, ans);
    return ans;
    // Time Complexity: O(N!)
    // Space Complexity: O(N)
}
int main()
{
    vector<int> v{1, 2, 3};
    vector<vector<int>> sum = permute(v);
    print(sum);
    vector<vector<int>> sum1 = permuteBacktracking(v);
    print(sum1);
}