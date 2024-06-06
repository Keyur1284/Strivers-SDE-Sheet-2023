// Problem Link :- https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Solved by unordered_set
// Time Complexity :- O(2 * n)
// Space Complexity :- O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.length(), maxi = 0, left = 0, right = 0;
        unordered_set<char> st;

        while (right < len)
        {
            while (left <= right && st.count(s[right]))
            {
                st.erase(s[left]);
                left++;
            }
            
            st.emplace(s[right]);
            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};



// Solved by unordered_map (Most Optimized Solution)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.length(), maxi = 0, left = 0, right = 0;
        unordered_map<char, int> mp;

        while (right < len)
        {
            if (mp.find(s[right]) != mp.end())
            {
                left = max(left, mp[s[right]] + 1);
            }

            mp[s[right]] = right;
            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};