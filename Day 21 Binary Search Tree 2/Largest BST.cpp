// Problem Link :- https://practice.geeksforgeeks.org/problems/largest-bst/1

// Solved by Recursive Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    int size (Node* node)
    {
        if (node == NULL)
            return 0;
            
        return 1 + size (node->left) + size(node->right);
    }
    
    bool checkBST (Node* node, int mini, int maxi)
    {
        if (node == NULL)
            return true;
            
        if (node->data <= mini || node->data >= maxi)
            return false;
            
        return checkBST (node->left, mini, node->data) && checkBST (node->right, node->data, maxi);
    }
    
    int largestBst(Node *root)
    {
    	if (checkBST (root, INT_MIN, INT_MAX))
    	    return size(root);
    	    
    	return max (largestBst(root->left), largestBst(root->right));
    }
};



// Optimized Solution
// Time Complexity :- O(n)
// Space Complexity :- O(1)

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    class TreeNode{
      public:
      
      int minNode, maxNode, size;
      
      TreeNode (int a, int b, int c)
      {
          minNode = a;
          maxNode = b;
          size = c;
      }
        
    };
    
    TreeNode findLargestBST (Node* node)
    {
        if (node == NULL)
            return TreeNode (INT_MAX, INT_MIN, 0);
            
        TreeNode left = findLargestBST (node->left);
        TreeNode right = findLargestBST (node->right);
        
        if (left.maxNode < node->data && node->data < right.minNode)
            return TreeNode (min(left.minNode, node->data), max(right.maxNode, node->data), left.size + right.size + 1);
            
        else
            return TreeNode (INT_MIN, INT_MAX, max(left.size, right.size));
    }
    
    int largestBst(Node *root)
    {
    	return findLargestBST(root).size;
    }
};