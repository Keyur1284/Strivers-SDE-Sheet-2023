// Problem Link :- https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Solved by using priority_queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int, int>> vec;
    	
    	for (int i = 0; i < n; i++)
    	    vec.emplace_back(arr[i], dep[i]);
    	    
    	sort (vec.begin(), vec.end());
    	
    	int plat = 1;
    	priority_queue<int, vector<int>, greater<int>> pq;
    	pq.emplace(vec[0].second);
    	
    	for (int i = 1; i < n; i++)
    	{
    	    if (pq.top() >= vec[i].first)
    	        plat++;
    	    
    	    else
    	        pq.pop();
    	        
    	    pq.emplace(vec[i].second);
    	}
    	    
    	return plat;
    }
};



// Solved by Sorting both arrival and departure time separately
// Approach similar to merge sort
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort (arr, arr + n);
    	sort (dep, dep + n);
    	
    	int i = 0, j = 0, ans = 0, plat = 0;
    	
    	while (i < n && j < n)
    	{
    	    if (arr[i] <= dep[j])
    	    {
    	        plat++;
    	        i++;
    	    }
    	    
    	    else
    	    {
    	        plat--;
    	        j++;
    	    }
    	    
    	    ans = max(ans, plat);
    	}
    	    
    	return ans;
    }
};



// Solved by making a vector of size 2360
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<int> platform (2361, 0);
    	
    	for (int i = 0; i < n; i++)
    	{
    	    platform[arr[i]]++;
    	    platform[dep[i] + 1]--;
    	}
    	    
    	int plat = 0, ans = 0;
    	
    	for (auto &it : platform)
    	{
    	    plat += it;
    	    ans = max (ans, plat);
    	}
    	    
    	return ans;
    }
};