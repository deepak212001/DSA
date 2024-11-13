/*

Search in a sorted 2D matrix


Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Examples
Example 1:
Input Format:
 N = 3, M = 4, target = 8,
mat[] = 
1 2 3 4
5 6 7 8 
9 10 11 12
Result:
 true
Explanation:
 The ‘target’  = 8 exists in the 'mat' at index (1, 3).

Example 2:
Input Format:
 N = 3, M = 3, target = 78,
mat[] = 
1 2 4
6 7 8 
9 10 34
Result:
 false
Explanation:
 The ‘target' = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.

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
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}


bool Better(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) 
    {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) 
        {
            return binarySearch(matrix[i], target);
        }
    }
    return false;

    // TC O(N*logM)
    // SC O(1)
}

bool Optimal(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) 
            return true;
        else if (matrix[row][col] < target) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return false;

    // TC O(log(N*M))
    // SC O(1)
}
bool Optimal2(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row=0;
    int col= m-1;
      
    while(row<n && col>=0){
      if ( matrix[row][col] == target)
        return 1;
      else if( matrix[row][col] < target )
        row++;
      else 
            col--;
    }
    return 0;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    BruteForce(matrix, 8) == true ? cout << "True\n" : cout << "False\n";
    Better(matrix, 8) == true ? cout << "True\n" : cout << "False\n";
    Optimal(matrix, 8) == true ? cout << "True\n" : cout << "False\n";
    Optimal2(matrix, 8) == true ? cout << "True\n" : cout << "False\n";
}

