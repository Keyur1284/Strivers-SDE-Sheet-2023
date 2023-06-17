// Problem Link :- https://leetcode.com/problems/next-greater-element-i/

// Solved using stack and unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        stack <int> st;

        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            mp[nums2[i]] = (st.empty()) ? -1 : st.top();

            st.emplace(nums2[i]);
        }

        vector<int> ans;

        for (auto &it : nums1)
            ans.emplace_back(mp[it]);

        return ans;
    }
};