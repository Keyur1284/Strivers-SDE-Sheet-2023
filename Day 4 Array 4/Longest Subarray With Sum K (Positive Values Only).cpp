// Problem Link :- https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399

// Time Complexity :- O(n)
// Space Complexity :- O(1)

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    
    int n = a.size(), maxLen = 0;
    long long sum = 0;

    for (int left = 0, right = 0; right < n; right++)
    {
        sum += a[right];

        while (sum > k)
            sum -= a[left++];

        if (sum == k)
        {
            int len = right - left + 1;
            maxLen = max(len, maxLen);
        }
    }

    return maxLen;
}