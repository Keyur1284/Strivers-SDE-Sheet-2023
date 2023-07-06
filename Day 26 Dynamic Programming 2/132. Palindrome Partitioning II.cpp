//Problem Link :- https://leetcode.com/problems/palindrome-partitioning-ii/

//Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    
    bool isPalindrome (string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    int func (int start, int n, vector <int> &dp, string &s)
    {
        if (start == n)
            return 0;
        
        if (dp[start] != -1)
            return dp[start];
        
        int mini = INT_MAX;
        
        for (int end = start; end < n; end++)
        {
            if (isPalindrome(s, start, end))
            {
                int cost = 1 + func (end + 1, n, dp, s);
                mini = min (mini, cost);
            }
        }
        
        return dp[start] = mini;
    }
    
    int minCut(string s) {

        int n = s.size();
        vector <int> dp (n, -1);
        
        return func (0, n, dp, s) - 1;      
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    bool isPalindrome (string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    int minCut(string s) {
        
        int n = s.size();
        vector <int> dp (n + 1, 0);
        dp[n] = 0;       //Base Case (Can be omitted)
        
        for (int start = n - 1; start >= 0; start--)
        {
            int mini = INT_MAX;
        
            for (int end = start; end < n; end++)
            {
                if (isPalindrome(s, start, end))
                {
                    int cost = 1 + dp[end + 1];
                    mini = min (mini, cost);
                }
            }

             dp[start] = mini;
        }
        
        return dp[0] - 1;
        
    }
};



// Problem Link :- https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

// User function Template for C++

class Solution{
public:
    
    int solve (int start, int len, vector<vector<bool>> &dp, vector<int> &cost, string &s)
    {
        if (start == len)
            return 0;
            
        if (cost[start] != -1)
            return cost[start];
            
        int minCost = INT_MAX;
        
        for (int end = start; end < len; end++)
        {
            if (s[end] == s[start] && (end - start <= 2 || dp[start + 1][end - 1]))
            {
                dp[start][end] = true;
                int currcost = 1 + solve (end + 1, len, dp, cost, s);
                minCost = min(currcost, minCost);
            }
        }
        
        return cost[start] = minCost;
    }

    int palindromicPartition(string &str)
    {
        int len = str.length();
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        vector<int> cost(len, -1);
        
        return solve (0, len, dp, cost, str) - 1;
    }
};