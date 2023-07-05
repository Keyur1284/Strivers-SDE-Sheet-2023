//Problem Link :- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Solved by Memoization Method
// Time Complexity :- O(n^3)
// Space Complexity :- O(n^2)

class Solution{
public:
    
    int solve (int left, int right, vector<vector<int>> &dp, int arr[])
    {
        if (left == right)
            return 0;
            
        if (dp[left][right] != -1)
            return dp[left][right];
            
        int minCost = INT_MAX;
            
        for (int k = left; k < right; k++)
        {
            int cost = arr[left - 1] * arr[k] * arr[right] + solve (left, k, dp, arr) + solve (k + 1, right, dp, arr);
            minCost = min(cost, minCost);
        }
        
        return dp[left][right] = minCost; 
    }

    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp (n, vector<int> (n, -1));
        
        return solve (1, n - 1, dp, arr);
    }
};

//Solved by Tabulation Method

class Solution{
public:
    
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp (n, vector<int> (n, 0));
        
        for (int left = n - 1; left >= 1; left--)
        {
            for (int right = left + 1; right < n; right++)
            {
                int minCost = INT_MAX;
                
                for (int k = left; k < right; k++)
                {
                    int cost = arr[left - 1] * arr[k] * arr[right] + dp[left][k] + dp[k + 1][right];
                    minCost = min(cost, minCost);
                }
                
                dp[left][right] = minCost;
            }
            
        }
        
        return dp[1][n - 1];
    }
};