// Problem Link :- https://practice.geeksforgeeks.org/problems/mirror-tree/1

// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(h)

// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        
        if (node == NULL)
            return;
        
        swap (node->left, node->right);
        mirror (node->left);
        mirror (node->right);
    }
};



// Solved by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        
        if (node == NULL)
            return;
        
        queue<Node*> q;
        q.emplace(node);
        
        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            
            swap(curr->left, curr->right);
            
            if (curr->left)
                q.emplace(curr->left);
                
            if (curr->right)
                q.emplace(curr->right);
        }
    }
};