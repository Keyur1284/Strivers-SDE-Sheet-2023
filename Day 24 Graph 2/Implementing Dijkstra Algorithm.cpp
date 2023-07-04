// Problem Link :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Time Complexity :- O(ElogV)      E = no. of edges, V = no. of vertices  (E = V^2) {Worst Case}
// Space Complexity :- O(E + V)

// Dijkstra's Algorithm is used to find the shortest path 
// from a source vertex to all other vertices in a graph with non-negative edge weight.
// It fails in case of graphs containing negative edges.
// If a graph has negative cycle, it will give TLE i.e. it will run for infinite time.
// In such cases, for detecting a negative cycle, we use Bellman Ford's Algorithm

// Solved using Priority Queue

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.emplace(0, S);
        dist[S] = 0;
        
        while (!pq.empty())
        {
            int node = pq.top().second;
            int steps = pq.top().first;
            pq.pop();
            
            for (auto &it : adj[node])
            {
                if (it[1] + steps < dist[it[0]])
                {
                    dist[it[0]] = it[1] + steps;
                    pq.emplace(dist[it[0]], it[0]);
                }
            }
        }
        
        return dist;
    }
};



// Solved using Set

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;
        
        st.emplace(0, S);
        dist[S] = 0;
        
        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int steps = it.first;
            st.erase(it);
            
            for (auto &it : adj[node])
            {
                if (it[1] + steps < dist[it[0]])
                {
                    dist[it[0]] = it[1] + steps;
                    st.emplace(dist[it[0]], it[0]);
                }
            }
        }
        
        return dist;
    }
};