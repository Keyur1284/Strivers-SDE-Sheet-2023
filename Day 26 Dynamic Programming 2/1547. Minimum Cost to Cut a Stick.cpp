// Problem Link :- https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

// Solved by Memoization
// Time Complexity :- O(n^3)
// Space Complexity :- O(n^2)

class Solution {
public:

    int func (int left, int right, vector<vector<int>> &dp, vector<int>& cuts)
    {
        if (left > right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int minCost = INT_MAX;

        for (int index = left; index <= right; index++)
        {
            int cost = cuts[right + 1] - cuts[left - 1] + func (left, index - 1, dp, cuts) + func (index + 1, right, dp, cuts);
            minCost = min(minCost, cost);
        }

        return dp[left][right] = minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        
        int size = cuts.size();
        cuts.emplace_back(n);
        cuts.emplace(cuts.begin(), 0);
        sort (cuts.begin(), cuts.end());
        vector<vector<int>> dp (size + 1, vector<int> (size + 1, -1));

        return func (1, size, dp, cuts);
    }
};



// Solved by Tabulation

class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        
        int size = cuts.size();
        cuts.emplace_back(n);
        cuts.emplace(cuts.begin(), 0);
        sort (cuts.begin(), cuts.end());
        vector<vector<int>> dp (size + 2, vector<int> (size + 2, 0));

        for (int left = size; left >= 1; left--)
        {
            for (int right = left; right <= size; right++)
            {
                int mincost = INT_MAX;

                for (int index = left; index <= right; index++)
                {
                    int cost = cuts[right + 1] - cuts[left - 1] + dp[left][index - 1] + dp[index + 1][right];
                    mincost = min(mincost, cost);
                }

                dp[left][right] = mincost;
            }
        }

        return dp[1][size];
    }
};