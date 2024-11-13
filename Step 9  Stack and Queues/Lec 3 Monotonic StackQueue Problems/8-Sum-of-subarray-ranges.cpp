/*

You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.

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
            int largest = INT_MIN;
            int smallest = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                largest = max(largest, arr[k]);
                smallest = min(smallest, arr[k]);
            }
            sum += (largest - smallest);
        }
    }
    return sum;

    // TC O(N^3)
    // SC O(1)
}

int Better(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int largest = INT_MIN;
        int smallest = INT_MAX;
        for (int j = i; j < arr.size(); j++)
        {
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum += (largest - smallest);
        }
    }
    return sum;

    // TC O(N^2)
    // SC O(1)
}

int Optimal(vector<int> &nums)
{
    int n = nums.size();
    long long sum = 0;
    stack<int> st;
    vector<int> minPrev(n, -1), minNext(n, n), maxPrev(n, -1), maxNext(n, n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            minPrev[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            minNext[i] = st.top();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            maxPrev[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            maxNext[i] = st.top();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        long long leftMin = i - minPrev[i], rightMin = minNext[i] - i;
        long long leftMax = i - maxPrev[i], rightMax = maxNext[i] - i;
        sum += (leftMax * rightMax - leftMin * rightMin) * nums[i];
    }
    return sum;
}

int main()
{
    vector<int> vec = {1, 2, 3};
    cout << BruteForce(vec) << endl;
    cout << Better(vec) << endl;
    cout << Optimal(vec) << endl;

    return 0;
}