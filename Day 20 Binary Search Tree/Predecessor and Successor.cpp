// Problem Link :- https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// Solved by Recursive Approach
// Time Complexity :- O(h) where h is the height of the tree
// Space Complexity :- O(h)

/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if (root == NULL)
            return;
            
        if (root->key == key)
        {
            if (root->left)
            {
                Node* curr = root->left;
                
                while (curr->right)
                    curr = curr->right;
                    
                pre = curr;
            }
            
            if (root->right)
            {
                Node* curr = root->right;
                
                while (curr->left)
                    curr = curr->left;
                    
                suc = curr;
            }
            
            return;
        }
        
        if (root->key < key)
        {
            pre = root;
            findPreSuc (root->right, pre, suc, key);
        }
        
        else
        {
            suc = root;
            findPreSuc (root->left, pre, suc, key);
        }
    }
};



/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void findPredecessor (Node *root, Node*& pre, int &key)
    {
        Node* node = root;
        
        while (node)
        {
            if (node->key < key)
            {
                pre = node;
                node = node->right;
            }
            
            else
                node = node->left;
        }
    }
    
    void findSuccessor (Node *root, Node*& suc, int &key)
    {
        Node* node = root;
        
        while (node)
        {
            if (node->key > key)
            {
                suc = node;
                node = node->left;
            }
            
            else
                node = node->right;
        }
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        findPredecessor (root, pre, key);
        findSuccessor (root, suc, key);
    }
};