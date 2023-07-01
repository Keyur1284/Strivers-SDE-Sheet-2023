// Problem Link :- https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// Solved by Iterative Approach
// Time Complexity :- O(log_2 N)
// Space Complexity :- O(1)


// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int ceil = -1;
    
    while (root)
    {
        if (root->data == input)
        {
            ceil = root->data;
            return ceil;
        }
        
        else if (root->data < input)
            root = root->right;
            
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    
    return ceil;
}



// Solved by Recursive Approach
// Time Complexity :- O(log_2 N)
// Space Complexity :- O(log_2 N)

// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    
    if (root == NULL) 
        return -1;

    if (root->data == input)
        return root->data;
        
    if (root->data < input)
        return findCeil (root->right, input);
        
    int ceil = findCeil (root->left, input);
    
    return (ceil >= input) ? ceil : root->data;
}
