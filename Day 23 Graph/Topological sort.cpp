//Problem Link :- https://practice.geeksforgeeks.org/problems/topological-sort/1

//Topological sort is valid only for directed acyclic graphs
//Definition : Linear ordering of vertices such that if there is an edge u -> v then u appears before v in that ordering

//Topological done by bfs is also known as Kahn's Algorithm

// Solved by BFS
// Time Complexity :- O(N + E)
// Space Complexity :- O(N + E)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.

	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector <int> indegree (v, 0), ans;
	    
	    for (int i = 0; i < v; i++)
	    {
	        for (auto it : adj[i])
	            indegree[it]++;
	    }
	    
	    queue <int> q;
	    
	    for (int i = 0; i < v; i++)
	    {
	        if (indegree[i] == 0)
	            q.emplace(i);
	    }
	    
	    while (!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.emplace_back(node);
	        
	        for (auto it : adj[node])
	        {
	            indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
	        }
	    }
	    
	    return ans;
	}
};



// Solved by DFS

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
	void DFS (int node, vector <int> &vis, stack <int> &st, vector<int> adj[])
	{
	    vis[node] = 1;
	    
	    for (auto it : adj[node])
	    {
	        if (!vis[it])
	            DFS(it, vis, st, adj);
	    }
	    
	    st.emplace(node);
	}
	
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector <int> vis (v, 0), ans;
	    stack <int> st;
	    
	    for (int i = 0; i < v; i++)
	    {
	        if (!vis[i])
	            DFS (i, vis, st, adj);
	    }
	    
	    while (!st.empty())
	    {
	        ans.emplace_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}
