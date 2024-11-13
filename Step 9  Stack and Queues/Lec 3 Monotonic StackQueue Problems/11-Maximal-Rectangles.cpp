/*

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

int histogram(vector<int> &heights)
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

    // TC O(M)
    // SC O(M)
}

int maxRectangle(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxArea = 0;
    vector<vector<int>> prefixSum(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j] != 0)
            {
                k++;
                prefixSum[i][j] = k;
            }
            else
                k = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, histogram(prefixSum[i]));
    }
    return maxArea;

    // TC O(N*M) + O(N*M)
    // SC O(N*M) + O(M)
}

int maximalRectangle(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> heights(c + 1, 0);
    int maxArea = 0;

    for (const auto &row : matrix)
    {
        for (int i = 0; i < c; i++)
        {
            heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
        }

        int n = heights.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i, minHeight = INT_MAX; j < n; j++)
            {
                minHeight = min(minHeight, heights[j]);
                int area = minHeight * (j - i + 1);
                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> A = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0},
    };

    cout << "Area of maximum rectangle is " << maxRectangle(A);

    return 0;
}
