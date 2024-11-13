/*
Subset - II | Print all the Unique Subsets


Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

Examples:

Example 1:

Input: array[] = [1,2,2]

Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]

Output: [ [ ], [1] ]

Explanation: Only two unique subsets are available

*/

#include <bits/stdc++.h>

using namespace std;
void printAns(vector<vector<int>> &ans)
{
    cout << "\nThe unique subsets are " << endl;
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
}

void fun(vector<int> &nums, int ind, vector<int> ds, set<vector<int>> &res)
{
    if (ind == nums.size())
    {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
    }
    ds.push_back(nums[ind]);
    fun(nums, ind + 1, ds, res);
    ds.pop_back();

    fun(nums, ind + 1, ds, res);
}

vector<vector<int>> BruteForce(vector<int> &nums)
{
    vector<vector<int>> ans;
    set<vector<int>> res;
    vector<int> temp;
    fun(nums, 0, temp, res);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        ans.push_back(*it);
    }
    return ans;

    // Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.
    // Space Complexity:  O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another O(2^n *k) is also used.
}

void findSubsetsOptimal(vector<int> &nums, int ind, vector<int> &temp, vector<vector<int>> &ans)
{
    ans.push_back(temp);

    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        findSubsetsOptimal(nums, i + 1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> Optimal(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(),nums.end());
    findSubsetsOptimal(nums, 0, temp, ans);
    return ans;

    // TC O(2^n)
    // SC O(2^n*k)
}

int main()
{

    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = BruteForce(nums);
    printAns(ans);
    vector<vector<int>> ans1 = Optimal(nums);
    printAns(ans1);
    return 0;
}