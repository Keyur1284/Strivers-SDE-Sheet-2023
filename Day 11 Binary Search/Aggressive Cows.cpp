// Problem Link :- https://practice.geeksforgeeks.org/problems/aggressive-cows/0

// Solved by Binary Search
// Time Complexity :- O(n * log(1e9))
// Space Complexity :- O(1)

// User function Template for C++

class Solution {
public:

    bool check (int dis, int n, int k, vector<int> &stalls)
    {
        int cows = 1, last = stalls[0];
        
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= dis)
            {
                cows++;
                last = stalls[i];
                
                if (cows == k)
                    return true;
            }
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort (stalls.begin(), stalls.end());
        
        int low = 1, high = 1e9, mid, ans;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            if (check(mid, n, k, stalls))
            {
                ans = mid;
                low = mid + 1;
            }
            
            else
                high = mid - 1;
        }
        
        return ans;
    }
};