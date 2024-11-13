/*
N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle


58

0
Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen's placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

Examples:

Input: n = 4

Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]


*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    int dupRow = row;
    int dupCol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row--;
    }

    row = dupRow;
    col = dupCol;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = dupRow;
    col = dupCol;

    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row++;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    // BruteForce
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int row = 0; row < n; row++)
    {
        board[row] = s;
    }
    solve(0, board, ans, n);
    return ans;

    // TC O(N!*N)
    // SC O(N^2)
}

// Optimal Approch
void solveOptimal(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftRow, vector<int> &UpperDiagonal, vector<int> &LowerDiagonal)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && UpperDiagonal[row + col] == 0 && LowerDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            UpperDiagonal[row + col] = 1;
            LowerDiagonal[n - 1 + col - row] = 1;

            solveOptimal(col + 1, board, ans, n, leftRow, UpperDiagonal, LowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            UpperDiagonal[row + col] = 0;
            LowerDiagonal[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<string>> solveNQueensOptimal(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int row = 0; row < n; row++)
    {
        board[row] = s;
    }
    vector<int> leftRow(n, 0), UpperDiagonal(2 * n - 1, 0), LowerDiagonal(2 * n - 1, 0);
    solveOptimal(0, board, ans, n, leftRow, UpperDiagonal, LowerDiagonal);
    return ans;

    // TC O(N!*N)
    // SC O(N)
}
int main()
{
    int n = 4;                                    // we are taking 4*4 grid and 4 queens
    vector<vector<string>> ans = solveNQueens(n); // BruteForce
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }

    vector<vector<string>> ans1 = solveNQueensOptimal(n); // BruteForce
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans1[0].size(); j++)
        {
            cout << ans1[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}