//Problem Link :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


//Solved by BFS
// Time Complexity :- O(E + V)
// Space Complexity :- O(E + V)

class Solution {
  public:
  
    bool checkForCycle (int node, vector <int> &vis, vector<int> adj[])
    {
        queue <pair<int, int>> BFS;
        BFS.emplace(node, -1);
        vis[node] = 1;
        
        while (!BFS.empty())
        {
            int cur = BFS.front().first;
            int par = BFS.front().second;
            BFS.pop();
            
            for (auto &it : adj[cur])
            {
                if (!vis[it])
                {
                    BFS.emplace(it, cur);
                    vis[it] = 1; 
                }
                
                else if (it != par)
                    return true;
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int v, vector<int> adj[]) {
        
        vector <int> vis (v, 0);
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, vis, adj))
                    return true;
            }
        }
        
        return false;
    }
};


//Solved by DFS

class Solution {
  public:
  
    bool checkForCycle (int node, int parent, vector <int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
    
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                if(checkForCycle(it, node, vis, adj))
                    return true;
            }
            
            else if (it != parent)
                return true;
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int v, vector<int> adj[]) {
        
        vector <int> vis (v, 0);
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, -1, vis, adj))
                    return true;
            }
        }
        
        return false;
    }
};