// Problem Link :- https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Solved by greedy approach (sorting in descending order based on profit)
// Time Complexity = O(nlogn + n^2)
// Space Complexity = O(n)

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
            for (int j = arr[i].dead; j >= 1; j--)
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



// Solved by using custom priority_queue
// Time Complexity = O(nlogn)
// Space Complexity = O(n)

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
    
    struct pqComp {
      
        bool operator()(Job &j1, Job &j2)
        {
            return j1.profit < j2.profit;
        }
    };
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort (arr, arr + n, comp);
        
        priority_queue<Job, vector<Job>, pqComp> pq;
            
        int jobs = 0, profit = 0;
        
        for (int i = n - 1; i >= 0; i--)
        {
            int slots;
            
            if (i == 0)
                slots = arr[i].dead;
                
            else
                slots = arr[i].dead - arr[i - 1].dead;
                
            pq.emplace(arr[i]);
            
            while(slots-- && !pq.empty())
            {
                auto job = pq.top();
                pq.pop();
                
                jobs++;
                profit += job.profit;
            }
        }
        
        return {jobs, profit};
    } 
};



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