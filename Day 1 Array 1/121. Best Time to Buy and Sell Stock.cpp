// Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Solved using Dynamic Programming
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> dp(n, 0);

        int minCost = prices[0];
        
        for(int i = 1; i < n; i++)
        {
            int profit = prices[i] - minCost;
            dp[i] = max(dp[i - 1], profit);
            minCost = min(minCost, prices[i]);
        }

        return dp[n - 1];
    }
};



// Solved using constant space
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), minCost = prices[0], maxProfit = 0;
        
        for (int i = 1; i < n; i++)
        {
            int profit = prices[i] - minCost;
            maxProfit = max(maxProfit, profit);
            minCost = min(minCost, prices[i]);
        }
        
        return maxProfit;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), minCost = INT_MAX, maxProfit = 0;
        
        for (int i = 0; i < n; i++)
        {
            minCost = min(minCost, prices[i]);
            int profit = prices[i] - minCost;
            maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};



// Solved by finding maximum element from right side
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int> maxi(n, 0);
        
        maxi[n - 1] = prices[n - 1];
        int maxProfit = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            maxi[i] = max(maxi[i + 1], prices[i]);
        }

        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, maxi[i] - prices[i]);
        }

        return maxProfit;
    }
};