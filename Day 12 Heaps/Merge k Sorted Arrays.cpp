// Problem Link :- https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> &arr, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &vec : arr)
        {
            for (auto &it : vec)
                pq.emplace(it);
        }
    
        vector<int> merged;
    
        while (!pq.empty())
        {
            merged.emplace_back(pq.top());
            pq.pop();
        }
    
        return merged;
    }
};



// Solved using priority_queue  (Optimized Solution)
// Time Complexity :- O(nlogk)
// Space Complexity :- O(k)

//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> &arr, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i][0], {i, 0}});
        }
    
        vector<int> merged;
    
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
    
            merged.emplace_back(it.first);
    
            auto pair = it.second;
            int arrIndex = pair.first;
            int eleIndex = pair.second;
    
            if (eleIndex + 1 < arr[arrIndex].size())
            {
                pq.push({arr[arrIndex][eleIndex + 1], {arrIndex, eleIndex + 1}});
            }
        }
    
        return merged;
    }
};