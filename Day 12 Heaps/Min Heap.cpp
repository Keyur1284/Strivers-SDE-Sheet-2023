// Problem Link :- https://www.codingninjas.com/codestudio/problems/min-heap_4691801

// Solved using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for (auto &it : q)
    {
        if (it[0] == 0)
            pq.emplace(it[1]);

        else
        {
            ans.emplace_back(pq.top());
            pq.pop();
        }
    }

    return ans;
}
