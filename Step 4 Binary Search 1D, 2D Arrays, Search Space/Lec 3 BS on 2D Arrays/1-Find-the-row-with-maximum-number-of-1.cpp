/*
Find the row with maximum number of 1's


24

2
Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

Pre-requisite: Lower Bound implementation, Upper Bound implementation, & Find the first occurrence of a number.

Examples
Example 1:
Input Format:
 n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result:
 0
Explanation:
 The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
Input Format:
 n = 2, m = 2 , 
mat[] = 
0 0
0 0
Result:
 -1
Explanation:
  The matrix does not contain any 1. So, -1 is the answer.

*/




#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<vector<int>> &matrix, int n, int m) 
{
    int cnt_max = 0;
    int index = -1;


    for (int i = 0; i < n; i++) 
    {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) 
            cnt_ones += matrix[i][j];
            
        if (cnt_ones > cnt_max) 
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;

    // TC O(N*M)
    // SC 0(1)
}

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int Binary(vector<vector<int>> &matrix, int n, int m) 
{
    int cnt_max = 0;
    int index = -1;


    for (int i = 0; i < n; i++) 
    {
  
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) 
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
    // TC O(N*logM)
    // SC O(1)
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<BruteForce(matrix, n, m) << '\n';
    cout << "The row with maximum no. of 1's is: " <<Binary(matrix, n, m) << '\n';
}

