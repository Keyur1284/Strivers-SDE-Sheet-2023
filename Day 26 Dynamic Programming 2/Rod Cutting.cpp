// Problem Link :- https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

// Solved by Memoization Method
// Time Complexity :- O(n * rodLength)
// Space Complexity :- O(n * rodLength)

// User function Template for C++

class Solution{
  public:
    
    int solve (int index, int n, vector<vector<int>> &dp, int price[])
    {
        if (index == 0)
            return n * price[index];
            
        if (dp[index][n] != -1)
            return dp[index][n];
            
        int notCut = 0 + solve (index - 1, n, dp, price);
        int cut = INT_MIN;
        int rodLength = index + 1;
        
        if (rodLength <= n)
            cut = price[index] + solve (index, n - rodLength, dp, price);
            
        return dp[index][n] = max (cut, notCut);
    }
  
    int cutRod(int price[], int n) {
        
        vector<vector<int>> dp (n, vector<int> (n + 1, -1));
        return solve (n - 1, n, dp, price);
    }
};



// Solved by Tabulation Method

// User function Template for C++

class Solution{
  public:
  
    int cutRod(int price[], int n) {
        
        vector<vector<int>> dp (n, vector<int> (n + 1, 0));

        for (int index = 0; index < n; index++)
        {
            int rodLength = index + 1;
            
            for (int k = 1; k <= n; k++)
            {
                if (index == 0)
                {
                    dp[index][k] = k * price[index];
                    continue;
                }
                
                int notCut = 0 + dp[index - 1][k];
                int cut = INT_MIN;
                
                if (rodLength <= k)
                    cut = price[index] + dp[index][k - rodLength];
                    
                dp[index][k] = max(cut, notCut);
            }
        }
        
        return dp[n - 1][n];
    }
};



// Solved by Tabulation Method (Space Optimized)

// User function Template for C++

class Solution{
  public:
  
    int cutRod(int price[], int n) {
        
        vector<int> dp (n + 1, 0);

        for (int index = 0; index < n; index++)
        {
            int rodLength = index + 1;
            vector<int> temp (n + 1, 0);
            
            for (int k = 1; k <= n; k++)
            {
                if (index == 0)
                {
                    temp[k] = k * price[index];
                    continue;
                }
                
                int notCut = 0 + dp[k];
                int cut = INT_MIN;
                
                if (rodLength <= k)
                    cut = price[index] + temp[k - rodLength];
                    
                temp[k] = max(cut, notCut);
            }
            
            dp = temp;
        }
        
        return dp[n];
    }
};