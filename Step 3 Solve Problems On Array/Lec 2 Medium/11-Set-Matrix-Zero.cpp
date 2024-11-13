/*
Set Matrix Zero


334

7
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

Examples
Examples 1:
Input:
 matrix=[
        [1,1,1],
        [1,0,1],
        [1,1,1]]

Output:
 [
 [1,0,1],
 [0,0,0],
 [1,0,1]]

Explanation:
 Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

Input:
 matrix=[
 [0,1,2,0],
 [3,4,5,2],
 [1,3,1,5]]

Output:
[
[0,0,0,0],
[0,4,5,0],
[0,3,1,0]]

Explanation:
Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0

*/

#include <bits/stdc++.h>
using namespace std;

void makeRowBF(vector<vector<int>> &matrix, int n, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}
void makeColBF(vector<vector<int>> &matrix, int i, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}
vector<vector<int>> BruteForce(vector<vector<int>> &matrix, int n, int m)
{
    // in this method  any element is to 0 then that row and col all 1 change into -1;
    // after that i->0 to n and j->0 to m and any element equal to -1 then change to 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                makeRowBF(matrix, n, j);
                makeColBF(matrix, i, m);
            }
        }
    }

    // now change -1 to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }

    return matrix;

    // TC O((N+M)(N*M))
    // SC O(1)
}

vector<vector<int>> Better(vector<vector<int>> &matrix, int n, int m)
{
    int row[n] = {0};
    int col[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
    // TC O(N*M)
    // SC 0(N)+O(M)
}

vector<vector<int>> BetterMine(vector<vector<int>> &matrix, int n, int m)
{
    set<int> row;
    set<int> col;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for (auto it : row)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[it][j] = 0;
        }
    }

    for (auto it : col)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][it] = 0;
        }
    }
    return matrix;
    // TC O(N*M)
    // SC 0(x) x is equal to no of 0
}

vector<vector<int>> Optimal(vector<vector<int>> &matrix, int n, int m)
{
    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = BruteForce(matrix, n, m);
    cout << "The Final matrix is: \n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    ans = Better(matrix, n, m);
    cout << "The Final matrix is: \n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    ans = BetterMine(matrix, n, m);
    cout << "The Final matrix is: \n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> ans1 = Optimal(matrix, n, m);
    cout << "The Final matrix is: \n";
    for (auto it : ans1)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}