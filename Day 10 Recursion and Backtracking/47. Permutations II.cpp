// Problem Link :- https://leetcode.com/problems/permutations-ii/

// Solved by Back-tracking
// Time Complexity :- O(n * n!)
// Space Complexity :- O(n * n!)

class Solution {
public:

    void solve (int index, int &n, vector<vector<int>> &perm, vector<int> &nums)
    {
        if (index == n)
        {
            perm.emplace_back(nums);
            return;
        }

        unordered_set<int> vis;

        for (int i = index; i < n; i++)
        {
            if (vis.find(nums[i]) != vis.end())
                continue;

            vis.emplace(nums[i]);
            swap (nums[index], nums[i]);
            solve (index + 1, n, perm, nums);
            swap (nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        sort (nums.begin(), nums.end());
        vector<vector<int>> perm;

        solve (0, n, perm, nums);

        return perm;
    }
};