// Problem Link :- https://leetcode.com/problems/subsets-ii/

// Solved using Recursion
// Time Complexity :- O(2^n + nlogn)
// Space Complexity :- O(2^n)

class Solution {
public:

    void solve (int index, int &n, vector<int> &ds, set<vector<int>> &subset, vector<int> &nums)
    {
        if (index == n)
        {
            vector<int> temp = ds;
            sort (temp.begin(), temp.end());
            subset.emplace(temp);
            return;
        }

        ds.emplace_back(nums[index]);
        solve (index + 1, n, ds, subset, nums);
        ds.pop_back();
        solve (index + 1, n, ds, subset, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>> subset;
        vector<int> ds;

        solve (0, n, ds, subset, nums);

        vector<vector<int>> ans(subset.begin(), subset.end());

        return ans;
    }
};



class Solution {
public:

    void solve (int index, int &n, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums)
    {
        if (index == n)
        {
            ans.emplace_back(ds);
            return;
        }

        ds.emplace_back(nums[index]);
        solve (index + 1, n, ds, ans, nums);
        ds.pop_back();

        while (index + 1 < n && nums[index] == nums[index + 1])
            index++;

        solve (index + 1, n, ds, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        sort (nums.begin(), nums.end());
        
        vector<int> ds;
        vector<vector<int>> ans;

        solve (0, n, ds, ans, nums);

        return ans;
    }
};


// Solved using Bit-masking
// Time Complexity :- O(2^n + nlogn)
// Space Complexity :- O(2^n)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        sort (nums.begin(), nums.end());
        
        vector<vector<int>> ans;

        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> ds;

            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    ds.emplace_back(nums[j]);
            }

            ans.emplace_back(ds);
        }

        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

        return ans;
    }
};
