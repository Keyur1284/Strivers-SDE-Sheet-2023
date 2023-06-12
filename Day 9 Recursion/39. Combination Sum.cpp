// Problem Link :- https://leetcode.com/problems/combination-sum/

// Solved by Recursion
// Time Complexity :- O(2^(target * n))
// Space Complexity :- O(n * comb)

class Solution {
public:

    void solve (int index, int &n, int target, vector<int> &ds, vector<vector<int>> &combinations, vector<int>& candidates)
    {
        if (index == n)
        {
            if (target == 0)
                combinations.emplace_back(ds);

            return;
        }

        if (candidates[index] <= target)
        {
            ds.emplace_back(candidates[index]);
            solve (index, n, target - candidates[index], ds, combinations, candidates);
            ds.pop_back();
        }

        solve (index + 1, n, target, ds, combinations, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<vector<int>> combinations;
        vector<int> ds;

        solve (0, n, target, ds, combinations, candidates);

        return combinations;
    }
};