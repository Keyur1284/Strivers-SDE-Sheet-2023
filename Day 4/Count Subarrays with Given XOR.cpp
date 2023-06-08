// Problem Link :- https://www.codingninjas.com/codestudio/problems/1115652

// Solved by unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> mp;
    mp[0]++;
    int xorVal = 0, ans = 0;

    for (auto &it : arr)
    {
        xorVal ^= it;

        ans += mp[xorVal ^ x];

        mp[xorVal]++;
    }

    return ans;
}