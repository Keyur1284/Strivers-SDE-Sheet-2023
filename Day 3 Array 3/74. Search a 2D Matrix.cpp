// Problem Link :- https://leetcode.com/problems/search-a-2d-matrix/

// Solved by Linear Search
// Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == target)
                        return true;
                }
            }
        }

        return false;
    }
};

// Solved by Binary Search
// Time Complexity :- O(m + log(n))
// Space Complexity :- O(1)

class Solution {
public:

    bool binarySearch(vector<int> &row, int target)
    {
        int low = 0, high = row.size() - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (row[mid] == target)
                return true;

            if (row[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
            {
                return binarySearch(matrix[i], target);
                
                // return binary_search(matrix[i].begin(), matrix[i].end(), target);
            }
        }

        return false;
    }
};



// Solved by Binary Search
// Time Complexity :- O(log(n * m))
// Space Complexity :- O(1)

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            int row = mid / n, col = mid % n;
            
            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};