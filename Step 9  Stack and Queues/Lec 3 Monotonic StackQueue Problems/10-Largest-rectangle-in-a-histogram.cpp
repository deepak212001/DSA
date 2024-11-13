/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> arr, int n)
{
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int minHeight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, arr[j]);
            maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }
    return maxArea;
    // TC O(N*N)
    // SC O(1)
}

int Optimal1(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }
    
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }
    
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        
    }
    return maxA;

    // TC O(N)
    // SC O(N)
}

int Optimal2(vector<int> &histo)
{
    // nse ->
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;

    // TC O(N)+O(N)
    // SC O(N)
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3, 1};
    int n = 7;
    cout << "BruteForce The largest area in the histogram is " << BruteForce(arr, n) << endl;
    cout << "Optimal1 The largest area in the histogram is " << Optimal1(arr) << endl;
    cout << "Optimal2 The largest area in the histogram is " << Optimal2(arr) << endl;
    return 0;
}