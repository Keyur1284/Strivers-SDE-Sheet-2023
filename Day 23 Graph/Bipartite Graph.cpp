//Problem Link :- https://practice.geeksforgeeks.org/problems/bipartite-graph/1

// Solved by DFS
// Time Complexity :- O(E + V)
// Space Complexity :- O(E + V)

class Solution {
public:
	
	bool bipartiteDFS (int node, vector <int> &color, vector<int>adj[])
	{
	    if (color[node] == -1)
	        color[node] = 1;
	    
	    for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                
                if (bipartiteDFS (it, color, adj) == false)
                    return false;
            }
            
            else if (color[it] == color[node])
                return false;
        }
        
	    return true;
	}
	
	bool isBipartite(int v, vector<int>adj[]){
	    
	    vector <int> color (v, -1);
	    
	    for (int i = 0; i < v; i++)
	    {
	        if (color[i] == -1)
	            if (bipartiteDFS(i, color, adj) == false)
	                return false;
	    }
	    
	    return true;
	}

};



// Solved by BFS

class Solution {
public:
	
	bool bipartiteBFS (int node, vector <int> &color, vector<int>adj[])
	{
	    color[node] = 1;
	    
	    queue <int> q;
	    q.emplace(node);
	    
	    while (!q.empty())
	    {
	        int temp = q.front();
	        q.pop();
	        
	        for (auto it : adj[temp])
	        {
	            if (color[it] == -1)
	            {
	                color[it] = 1 - color[temp];
	                q.emplace(it);
	            }
	            
	            else if (color[it] == color[temp])
	                return false;
	        }
	    }
	    
	    return true;
	}
	
	bool isBipartite(int v, vector<int>adj[]){
	    
	    vector <int> color (v, -1);
	    
	    for (int i = 0; i < v; i++)
	    {
	        if (color[i] == -1)
	            if (bipartiteBFS(i, color, adj) == false)
	                return false;
	    }
	    
	    return true;
	}

};