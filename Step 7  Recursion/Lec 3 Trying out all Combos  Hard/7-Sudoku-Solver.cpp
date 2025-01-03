/*
Sudoku Solver


32

0
Problem Statement:

Given a 9x9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.

         1. All the rows should be filled with numbers(1 - 9) exactly once.

         2. All the columns should be filled with numbers(1 - 9) exactly once.

         3. Each 3x3 submatrix should be filled with numbers(1 - 9) exactly once.

Note: Character '.' indicates empty cell.

*/

#include <iostream>

#include <vector>

using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;
        if (board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i / 3)] == c)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solveSudoku(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;

    // TC O(9^(N-2))
    // SC O(1)
}
int main()
{
    // vector<vector<char>> board{
    //     {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
    //     {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
    //     {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
    //     {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
    //     {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
    //     {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
    //     {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
    //     {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
    //     {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};
    vector<vector<char>> board{
        {'.', '.', '.', '7', '.', '.', '5', '.', '4'},
        {'.', '.', '.', '8', '.', '.', '.', '.', '9'},
        {'.', '6', '7', '.', '.', '.', '3', '1', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '.', '3'},
        {'2', '4', '.', '9', '.', '3', '.', '7', '6'},
        {'3', '.', '.', '.', '.', '8', '.', '.', '.'},
        {'.', '2', '1', '.', '.', '.', '6', '4', '.'},
        {'6', '.', '.', '.', '.', '7', '.', '.', '.'},
        {'9', '.', '8', '.', '.', '2', '.', '.', '.'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}