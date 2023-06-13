// Problem Link :- https://leetcode.com/problems/sudoku-solver/

// Solved by Back-tracking
// Time Complexity :- O(9^(n^2))    Here n = 9
// Space Complexity :- O(1)

class Solution {
public:

    bool isValid (int row, int col, char k, vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == k || board[i][col] == k)
                return false;

            if (board[3 * (row/3) + i/3][3 * (col/3) + i%3] == k)
                return false;
        }

        return true;
    }

    bool solve (vector<vector<char>>& board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isValid (row, col, k, board))
                        {
                            board[row][col] = k;

                            if (solve(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        solve (board);
    }
};