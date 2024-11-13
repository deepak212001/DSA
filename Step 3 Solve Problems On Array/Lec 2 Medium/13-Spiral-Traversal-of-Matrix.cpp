/*
Spiral Traversal of Matrix


Problem Statement: Given a Matrix, print the given matrix in spiral order.

Examples:

Example 1:
Input: Matrix[][] = { { 1, 2, 3, 4 },
              { 5, 6, 7, 8 },
              { 9, 10, 11, 12 },
                  { 13, 14, 15, 16 } }

Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Example 2:
Input: Matrix[][] = { { 1, 2, 3 },
                  { 4, 5, 6 },
              { 7, 8, 9 } }

Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<int> ans;
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    // right->bottom->left->top 

    while (top <= bottom && left <= right )
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;

        if (top <= bottom) 
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }
        if (left <= right) 
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
        
    }
    return ans;

    // TC O(N*M)
    // SC O(N*M)
}

int main()
{

    // Matrix initialization.
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};

    vector<int> ans = printSpiral(mat);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
