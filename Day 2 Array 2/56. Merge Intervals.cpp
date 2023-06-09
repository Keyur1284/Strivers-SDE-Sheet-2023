// Problem Link :- https://leetcode.com/problems/merge-intervals/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), start = intervals[0][0], end = intervals[0][1];

        vector<vector<int>> merged;

        for (int i = 1; i < n; i++)
        {
            if (end >= intervals[i][0])
                end = max(end, intervals[i][1]);

            else
            {
                merged.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        merged.push_back({start, end});

        return merged;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (auto &it : intervals)
        {
            if (merged.empty() || merged.back()[1] < it[0])
                merged.emplace_back(it);

            else
            {
                merged.back()[1] = max(merged.back()[1], it[1]);
            }
        }
        
        return merged;
    }
};