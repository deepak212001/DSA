/*

503. Next Greater Element II


Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.



Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]


*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int ind = (i + j) % n;
            if (arr[ind] > arr[i])
            {
                ans[i] = arr[ind];
                break;
            }
        }
    }
    return ans;
    // TC 0(N*N)
    // SC 0(N)
}

vector<int> Optimal(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int ind = i % n;
        while (!st.empty() && st.top() <= arr[ind])
            st.pop();
        if (!st.empty())
        {
            ans[ind] = st.top();
        }
        st.push(arr[ind]);
    }
    return ans;
    // TC 0(2N)
    // SC 0(N)

    /*
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        st.pop();
        if (!st.empty())
        ans[i] = arr[st.top()];
        st.push(i);
    }
    aase bhi kar skte hai index ko stack me dal ke
    */
}

int main()
{
    vector<int> ves{5, 7, 1, 2, 6, 0};
    // vector<int> ves{1, 2, 1};
    vector<int> res = bruteForce(ves);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n-----\n";
    vector<int> result = Optimal(ves);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}