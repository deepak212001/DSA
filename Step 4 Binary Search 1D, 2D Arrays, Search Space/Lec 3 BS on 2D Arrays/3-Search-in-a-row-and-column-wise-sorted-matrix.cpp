/*

Search in a row and column-wise sorted matrix


34

3
Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Pre-requisite: Search in a 2D sorted matrix

Examples
Example 1:
Input Format:
 N = 5, M = 5, target = 14
mat[] = 

Result:
 true
Explanation:
 Target 14 is present in the cell (3, 2)(0-based indexing) of the matrix. So, the answer is true.

Example 2:
Input Format:
 N = 3, M = 3, target = 12,
mat[] = 

Result:
 false
Explanation:
 As target 12 is not present in the matrix, the answer is false.

*/


#include <bits/stdc++.h>
using namespace std;

bool BruteForce(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size(), m = matrix[0].size();

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
    // TC O(N*M)
    // SC O(1)
}

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target) 
            return true;
        else if (target > nums[mid]) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return false;
}


bool Better(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) 
    {
        if(binarySearch(matrix[i], target))
            return true;
    }
    return false;

    // TC O(N*logM)
    // SC O(1)
}

bool Optimal(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) 
    {
        if (matrix[row][col] == target) 
            return true;
        else if (matrix[row][col] < target) 
            row++;
        else 
            col--;
    }
    return false;
    // TC O(N+M)
    // SC O(1)
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    BruteForce(matrix, 8) == true ? cout << "True\n" : cout << "False\n";
    Better(matrix, 8) == true ? cout << "True\n" : cout << "False\n";
    Optimal(matrix, 8) == true ? cout << "True\n" : cout << "False\n";
}