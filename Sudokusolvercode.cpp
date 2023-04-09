#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &sudoku, int row, int col, int value)
{

    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == value)
        {
            return false;
        }
        if (sudoku[i][col] == value)
        {
            return false;
        }
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(sudoku, i, j, val))
                    {
                        sudoku[i][j] = val;
                        bool find = solve(sudoku);
                        if (find == true)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> sudoku(9, vector<int>(9));
    cout << "Enter Sudoku Puzzle" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    bool ans = solve(sudoku);
    cout << "Printing solved sudoku" << endl;
    if (ans)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    }
}