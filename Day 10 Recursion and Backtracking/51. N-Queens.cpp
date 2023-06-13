// Problem Link :- https://leetcode.com/problems/n-queens/

// Solved by Back-tracking
// Time Complexity :- (n * n!)
// Space Complexity :- O(n^2)

class Solution {
public:

    bool isSafe (int row, int col, int n, vector<string> &board)
    {
        int dupR = row, dupC = col;

        // Checking for queen in the row

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;

            col--;
        }

        col = dupC;

        // Checking for queen in the upper left diagonal

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;

            row--, col--;
        }

        row = dupR, col = dupC;

        // Checking for queen in the lower left diagonal

        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;

            row++, col--;
        }

        return true;
    }

    void solve (int col, int &n, vector<string> &board, vector<vector<string>> &NQueens)
    {
        if (col == n)
        {
            NQueens.emplace_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, board))
            {
                board[row][col] = 'Q';
                solve (col + 1, n, board, NQueens);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n);
        string s(n, '.');

        for (auto &it : board)
            it = s;

        vector<vector<string>> NQueens;

        solve (0, n, board, NQueens);

        return NQueens;
    }
};



// Solved by Optimized Approach
// Time Complexity :- (n * n!)
// Space Complexity :- O(n^2)

class Solution {
public:

    bool isSafe (int row, int col, int n, vector<bool> &leftRow, vector<bool> &upperLeftDiagonal, vector<bool> &lowerLeftDiagonal)
    {
        return (!leftRow[row] && !lowerLeftDiagonal[row + col] && !upperLeftDiagonal[n - 1 + (row - col)]);
    }

    void solve (int col, int &n, vector<string> &board, vector<vector<string>> &NQueens, vector<bool> &leftRow,vector<bool> &upperLeftDiagonal, vector<bool> &lowerLeftDiagonal)
    {
        if (col == n)
        {
            NQueens.emplace_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, leftRow, upperLeftDiagonal, lowerLeftDiagonal))
            {
                board[row][col] = 'Q';
                leftRow[row] = true;
                lowerLeftDiagonal[row + col] = true;
                upperLeftDiagonal[n - 1 + (row - col)] = true;

                solve (col + 1, n, board, NQueens, leftRow, upperLeftDiagonal, lowerLeftDiagonal);

                board[row][col] = '.';
                leftRow[row] = false;
                lowerLeftDiagonal[row + col] = false;
                upperLeftDiagonal[n - 1 + (row - col)] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n);
        string s(n, '.');

        for (auto &it : board)
            it = s;

        vector<vector<string>> NQueens;
        vector<bool> leftRow (n, false), upperLeftDiagonal (2 * n - 1, false), lowerLeftDiagonal (2 * n - 1, false);

        solve (0, n, board, NQueens, leftRow, upperLeftDiagonal, lowerLeftDiagonal);

        return NQueens;
    }
};