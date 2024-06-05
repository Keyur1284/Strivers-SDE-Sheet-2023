// Problem Link :- https://leetcode.com/problems/majority-element/

// Solved by using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map <int, int> mp;

        for (auto &it : nums)
            mp[it]++;

        for (auto &it : mp)
        {
            if (it.second > n/2)
                return it.first;
        }

        return -1;
    }
};



// Solved by sorting the array
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};



// Solved by using bit manipulation
// Time Complexity :- O(n * 32)
// Space Complexity :- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int majority_element = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            int mask = (1 << bit);
            int count = 0;
            
            for (auto &it : nums)
            {
                if (mask & it)
                    count++;
            }

            if (count > n/2)
                majority_element |= mask;
        }

        return majority_element;
    }
};



// Solved by using Boyer Moore's Voting Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int majority_element = 0, count = 0;

        for (auto &it : nums)
        {
            if (majority_element == it)
                count++;
            
            else if (count == 0)
            {
                majority_element = it;
                count = 1;
            }
            
            else
                count--;
        }

        // We're directly returning the majority element as it is guaranteed that majority element always exists.
        // Had it been not given, we would traverse nums and check whether the element we found is 
        // really a majority element or not;
        
        return majority_element;
    }
};