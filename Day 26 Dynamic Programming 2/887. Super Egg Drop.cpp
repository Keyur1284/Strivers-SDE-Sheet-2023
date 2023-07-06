// Problem Link :- https://leetcode.com/problems/super-egg-drop/

// Solved by Memoization + Binary Search
// Time Complexity :- O(eggs * floors * log (floors))
// Space Complexity :- O(eggs * floors)

class Solution {
public:

    int solve (int eggs, int floors, vector<vector<int>> &dp)
    {
        if (eggs == 1 || floors <= 1)
            return floors;

        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int ans = INT_MAX;
        int low = 1, high = floors, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            int left = solve (eggs - 1, mid - 1, dp);
            int right = solve (eggs, floors - mid, dp);
            int steps = 1 + max(left, right);

            ans = min(ans, steps);

            if (left < right)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return dp[eggs][floors] = ans;
    }

    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp (k + 1, vector<int> (n + 1, -1));

        return solve (k, n, dp);
    }
};



// Solved by Tabulation + Binary Search

class Solution {
public:
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp (k + 1, vector<int> (n + 1, 0));

        for (int eggs = 1; eggs <= k; eggs++)
        {
            for (int floors = 0; floors <= n; floors++)
            {
                if (eggs == 1 || floors <= 1)
                {
                    dp[eggs][floors] = floors;
                    continue;
                }

                int ans = INT_MAX;
                int low = 1, high = floors, mid;

                while (low <= high)
                {
                    mid = (low + high) >> 1;

                    int left = dp[eggs - 1][mid - 1];
                    int right = dp[eggs][floors - mid];
                    int steps = 1 + max(left, right);

                    ans = min(ans, steps);

                    if (left < right)
                        low = mid + 1;

                    else
                        high = mid - 1;
                }

                dp[eggs][floors] = ans;
            }
        }

        return dp[k][n];
    }
};