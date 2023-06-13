// Problem Link :- https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// Solved by Back-tracking
// Time Complexity : O(M^V)
// Space Complexity : O(V)

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe (int node, int n, bool graph[101][101], int col, vector<int> &color)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != node && graph[i][node] && color[i] == col)
                return false;
        }
        
        return true;
    }
    
    bool solve (int node, bool graph[101][101], int m, int n, vector<int> &color)
    {
        if (node == n)
            return true;
            
        for (int col = 1; col <= m; col++)
        {
            if (isSafe(node, n, graph, col, color))
            {
                color[node] = col;
                
                if (solve (node + 1, graph, m, n, color))
                {
                    return true;
                }
                
                color[node] = 0;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<int> color (n, 0);
        
        return solve (0, graph, m, n, color);
    }
};