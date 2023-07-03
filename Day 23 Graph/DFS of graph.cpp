//Problem Link :- https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void DFS (int node, vector<int> adj[], vector <int> &vis, vector <int> &ans)
    {
        vis[node] = 1;
        ans.emplace_back(node);
        
        for (auto it : adj[node])
        {
            if (!vis[it])
                DFS(it, adj, vis, ans);
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        
        vector <int> vis(v, 0), ans;
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                DFS(i, adj, vis, ans);
        }
        
        return ans;
    }
};