// Problem Link :- https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

// Solved in best optimized way
// Time Complexity :- O(n)
// Space Complexity :- O(1)

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

    int maxSum = 0;

    struct Node {

        int mini, maxi, sum;

        Node (int a, int b, int c)
        {
            mini = a;
            maxi = b;
            sum = c;
        }
    };

    Node findMaxSumBST (TreeNode* node)
    {
        if (node == NULL)
            return Node(INT_MAX, INT_MIN, 0);

        Node left = findMaxSumBST (node->left);
        Node right = findMaxSumBST (node->right);

        if (left.maxi < node->val && node->val < right.mini)
        {
            maxSum = max(maxSum, node->val + left.sum + right.sum);
            return Node (min(left.mini, node->val), max(right.maxi, node->val), node->val + left.sum + right.sum);
        }

        else
            return Node (INT_MIN, INT_MAX, max(left.sum, right.sum));
    }

    int maxSumBST(TreeNode* root) {
        
        findMaxSumBST(root);

        return maxSum;
    }
};