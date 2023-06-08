// Problem Link :- https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399

// Time Complexity :- O(n)
// Space Complexity :- O(1)

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    
    long long n = a.size(), i = 0, j = 0, maxi = 0, sum = 0;

    while (j < n)
    {
        sum += a[j];

        while (i <= j && sum > k)
            sum -= a[i++];

        if (sum == k)
            maxi = max(maxi, j - i + 1);
        
        j++;
    }

    return maxi;
}