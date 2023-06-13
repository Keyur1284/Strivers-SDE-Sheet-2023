// Problem Link :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Solved by Back-tracking
// Time Complexity :- O(3^(n^2))
// Space Complexity :- O(L * X), L = length of the path, X = number of paths.

// User function template for C++

class Solution{
    public:
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    unordered_map<int, string> mp = {{0, "D"}, {1, "U"}, {2, "R"}, {3, "L"}};
    
    bool isValid (int x, int y, int n, vector<vector<int>> &grid)
    {
        return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]);
    }
    
    void DFS (int x, int y, int n, string &path, vector<string> &paths, vector<vector<int>> &grid)
    {
        if (x == n - 1 && y == n - 1)
        {
            paths.emplace_back(path);
            return;
        }
        
        grid[x][y] = 0;
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (isValid(newx, newy, n, grid))
            {
                path += mp[i];
                DFS (newx, newy, n, path, paths, grid);
                path.pop_back();
            }
        }
        
        grid[x][y] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        
        string path = "";
        vector<string> paths;
        
    if (isValid (0, 0, n, grid))    
        DFS (0, 0, n, path, paths, grid);
        
        return paths;
    }
};

    