/*
Rotate Image by 90 degree


Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.


Examples
Example 1:
Input:
 [[1,2,3],[4,5,6],[7,8,9]]

Output
: [[7,4,1],[8,5,2],[9,6,3]]

Explanation:
 Rotate the matrix simply by 90 degree clockwise and return the matrix.

Example 2:
Input:
 [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]

Output:
[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Explanation:
 Rotate the matrix simply by 90 degree clockwise and return the matrix

*/

#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> BruteForce(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    vector<vector<int>> ans(n, vector < int > (n, 0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[j][n-i-1]=matrix[i][j];
        }
    }
    return ans;

    // TC O(N^2)
    // SC O(N^2)
}


void Optimal(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i!=j)
                swap(matrix[i][j],matrix[j][i]); //transposing the matrix
        }
    }
     for(int i=0;i<n;i++)
        reverse(matrix[i].begin(),matrix[i].end());

    // reverse(matrix.begin(),matrix.end()); //Rotate 90 anti clockwise

    // TC O(N^2)
    // SC O(1)

}

void Optimal2(vector<vector<int>> &matrix)
{
    // first rotate then transport
    reverse(matrix.begin(),matrix.end()); 
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i!=j)
                swap(matrix[i][j],matrix[j][i]); //transposing the matrix
        }
    }
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    vector<vector<int>> ans=BruteForce(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Optimal(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Optimal2(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
