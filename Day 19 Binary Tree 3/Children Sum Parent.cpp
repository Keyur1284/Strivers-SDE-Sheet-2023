// Problem Link :- https://practice.geeksforgeeks.org/problems/children-sum-parent/1

// Time Complexity :- O(N)
// Space Complexity :- O(logN)

/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    int DFS (Node* node)
    {
        if (node == NULL)
            return 0;
            
        int left = DFS(node->left);
            
        if (left == -1)
            return -1;
        
        int right = DFS(node->right);
        
        if (right == -1)
            return -1;
        
        if ((node->left || node->right) && (node->data != left + right))
            return -1;
            
        return node->data;
    }
    
    int isSumProperty(Node *root)
    {
        return (DFS (root) != -1);
    }
};



/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    int isSumProperty(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 1;
            
        int left = 0, right = 0;
        
        if (root->left)
            left = root->left->data;
            
        if (root->right)
            right = root->right->data;
            
        return ((root->data == left + right) && (isSumProperty(root->left)) && (isSumProperty(root->right)));
    }
};