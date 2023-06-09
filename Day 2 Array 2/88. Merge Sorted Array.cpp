// Problem Link :- https://leetcode.com/problems/merge-sorted-array/

// Solved by using extra space
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> merged;
        int i = 0, j = 0;
        
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
                merged.emplace_back(nums1[i++]);
            
            else
                merged.emplace_back(nums2[j++]);
        }
        
        while (i < m)
            merged.emplace_back(nums1[i++]);
        
        while (j < n)
            merged.emplace_back(nums2[j++]);
        
        nums1 = merged;
    }
};


// Solved without using extra space

// Time Complexity :- O((m + n)* log(m + n))
// Space Complexity :- O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = m, j = 0; j < n; i++, j++)
            nums1[i] = nums2[j];

        sort (nums1.begin(), nums1.end());
    }
};



// Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] <= nums2[j])
                nums1[k--] = nums2[j--];
            
            else
                nums1[k--] = nums1[i--];
        }
        
        while (i >= 0)
            nums1[k--] = nums1[i--];
        
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};