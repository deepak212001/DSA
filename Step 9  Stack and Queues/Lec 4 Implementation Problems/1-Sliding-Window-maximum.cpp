/*

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7


Example 2:

Input: nums = [1], k = 1
Output: [1]

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> BruteForce(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i <= n - k; i++)
    {
        int maxi = nums[i];
        for (int j = i; j < i + k; j++)
            maxi = max(maxi, nums[j]);
        ans.push_back(maxi);
    }
    return ans;
}

vector<int> Optimal(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;

    // TC O(N)
    // SC O(K)
}

int main()
{
    int i, j, n, k = 3, x;
    vector<int> arr{4, 0, -1, 3, 5, 3, 6, 8};
    vector<int> ans;
    ans = BruteForce(arr, k);
    cout << "Maximum element in every " << k << " window " << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    cout << endl;
    ans = Optimal(arr, k);
    cout << "Maximum element in every " << k << " window " << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    return 0;
}