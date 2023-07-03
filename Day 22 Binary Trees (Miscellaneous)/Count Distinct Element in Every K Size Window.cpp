// Problem Link :- https://www.codingninjas.com/studio/problems/920336

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(k)

#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int left = 0, n = arr.size();
    vector<int> distinctEle;
    unordered_map<int, int> mp;

    for (int right = 0; right < n; right++)
    {
        mp[arr[right]]++;

        if (right - left + 1 == k)
        {
            distinctEle.emplace_back(mp.size());
            mp[arr[left]]--;

            if (mp[arr[left]] == 0)
                mp.erase(arr[left]);

            left++;
        }
    }
	
    return distinctEle;
}
