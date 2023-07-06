// Problem Link :- https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Solved by Greedy Approach (Sorting)
// Time Complexity :- O(nlogn + n^2)
// Space Complexity :- O(n)

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comp (Job &j1, Job &j2)
    {
        return j1.profit > j2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort (arr, arr + n, comp);
        
        int maxDead = 0;
        
        for (int i = 0; i < n; i++)
            maxDead = max (maxDead, arr[i].dead);
            
        vector<int> slots (maxDead + 1, -1);
        int jobs = 0, profit = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slots[j] == -1)
                {
                    jobs++;
                    profit += arr[i].profit;
                    slots[j] = arr[i].id;
                    break;
                }
            }
        }
        
        return {jobs, profit};
    } 
};



// Solved by Sorting and using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comp (Job &j1, Job &j2)
    {
        return j1.dead < j2.dead;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort (arr, arr + n, comp);
        
        priority_queue<int> pq;
            
        int jobs = 0, profit = 0;
        
        for (int i = n - 1; i >= 0; i--)
        {
            int slots;
            
            if (i == 0)
                slots = arr[i].dead;
                
            else
                slots = arr[i].dead - arr[i - 1].dead;
                
            pq.emplace(arr[i].profit);
            
            while(slots-- && !pq.empty())
            {
                profit += pq.top();
                jobs++;
                pq.pop();
            }
        }
        
        return {jobs, profit};
    } 
};



// Solved by Union Find
// Time Complexity :- O(nlogn)
// Space Complexity :- O(maxDeadline)

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class DSU {

private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }
    
    void merge (int u, int v)
    {
        parent[u] = v;
    }
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comp (Job &j1, Job &j2)
    {
        return j1.profit > j2.profit;
    }
    
    int findMaxDeadline (Job arr[], int n)
    {
        int deadline = 0;
        
        for (int i = 0; i < n; i++)
            deadline = max(deadline, arr[i].dead);
        
        return deadline;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort (arr, arr + n, comp);
        
        int maxDeadline = findMaxDeadline (arr, n);
        
        DSU dsu (maxDeadline);
        int jobs = 0, profit = 0;
        
        for (int i = 0; i < n; i++)
        {
            int slots = dsu.findPar(arr[i].dead);
            
            if (slots > 0)
            {
                jobs++;
                profit += arr[i].profit;
                
                int newPar = dsu.findPar(slots - 1);
                dsu.merge(slots, newPar);
            }
        }
        
        return {jobs, profit};
    } 
};