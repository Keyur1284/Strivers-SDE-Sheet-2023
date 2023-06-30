// Problem Link :- https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Solved by Recursive Approach
// Time Complexity :- O(N)
// Space Complexity :- O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* buildTree (int left, int right, vector<int> &nums)
    {
        if (left > right)
            return NULL;

        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree (left, mid - 1, nums);
        root->right = buildTree (mid + 1, right, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();

        return buildTree (0, n - 1, nums);
    }
};