// Problem Link :- https://leetcode.com/problems/max-consecutive-ones/

// Solved by traversing
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxi = 0, count = 0;

        for (auto &it : nums)
        {
            if (it)
                count++;

            else
                count = 0;

            maxi = max(maxi, count);
        }

        return maxi;
    }
};