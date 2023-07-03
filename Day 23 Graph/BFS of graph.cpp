//Problem Link :- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector <int> vis (v, 0), ans;
        
        vis[0] = 1;
        queue <int> q;
        q.emplace(0);
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.emplace_back(node);
            
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.emplace(it);
                }
            }
        }
        
        return ans;
    }
};