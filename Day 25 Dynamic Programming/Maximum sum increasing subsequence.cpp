// Problem Link :- https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution{
public:
	
	int solve (int index, int prev, int &n, vector<vector<int>> &dp, int arr[])
	{
	    if (index == n)
	        return 0;
	        
	    if (dp[index][prev + 1] != -1)
	        return dp[index][prev + 1];
	    
	    int notTake = solve (index + 1, prev, n, dp, arr);
	    int take = 0;
	         
	    if (prev == -1 || arr[index] > arr[prev])
	        take = arr[index] + solve (index + 1, index, n, dp, arr);
	        
	    return dp[index][prev + 1] = max(take, notTake);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp (n, vector<int> (n + 1, -1));
	    
	    return solve (0, -1, n, dp, arr);
	}  
};



// Solved by Tabulation Method

class Solution{
public:
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
	    
	    for (int index = n - 1; index >= 0; index--)
	    {
	        for (int prev = index - 1; prev >= -1; prev--)
	        {
	            int notTake = dp[index + 1][prev + 1];
	            int take = 0;
	            
	            if (prev == -1 || arr[index] > arr[prev])
	                take = arr[index] + dp[index + 1][index + 1];
	                
	            dp[index][prev + 1] = max(take, notTake);
	        }
	    }
	    
	    return dp[0][-1 + 1];
	}  
};


// Best Optimized Solution
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution{
public:
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n);
	    
	    for (int i = 0; i < n; i++)
	        dp[i] = arr[i];
	    
	    int maxi = 0;
	    
	    for (int index = 0; index < n; index++)
	    {
	        for (int prev = 0; prev < index; prev++)
	        {
	            if (arr[index] > arr[prev])
	                dp[index] = max(dp[index], arr[index] + dp[prev]);
	        }
	        
	        maxi = max(maxi, dp[index]);
	    }
	    
	    return maxi;
	}  
};