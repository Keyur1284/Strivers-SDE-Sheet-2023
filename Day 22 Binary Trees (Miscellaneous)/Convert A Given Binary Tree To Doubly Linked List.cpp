// Problem Link :- https://www.codingninjas.com/studio/problems/893106

// Solved by Recursive inorder traversal and storing node->data in vector
// Time Complexity :- O(N)
// Space Complexity :- O(N)

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void inorder (BinaryTreeNode<int>* node, vector<int> &vec)
{
    if (node == NULL)
        return;

    inorder (node->left, vec);
    vec.emplace_back(node->data);
    inorder (node->right, vec);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    
    vector<int> vec;
    inorder (root, vec);

    BinaryTreeNode<int>* head = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* curr = head, *prev = NULL;

    for (auto &it : vec)
    {
        curr->right = new BinaryTreeNode<int>(it);
        curr->left = prev;
        prev = curr;
        curr = curr->right;
    }

    return head->right;
}



// Solved by Recursive inorder traversal
// Time Complexity :- O(N)
// Space Complexity :- O(N)

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int>* head, *previous;

void inorder (BinaryTreeNode<int>* node)
{
    if (node == NULL)
        return;

    inorder (node->left);
    
    if (previous == NULL)
        head = node;

    else
    {
        node->left = previous;
        previous->right = node;
    }

    previous = node;
    
    inorder (node->right);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    
    head = NULL, previous = NULL;
    inorder (root);

    return head;
}



// Solved by morris inorder traversal
// Time Complexity :- O(N)
// Space Complexity :- O(1)

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    
    BinaryTreeNode<int>* head = NULL, *prev = NULL;
    BinaryTreeNode<int>* curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            if (head == NULL)
                head = curr;

            if (prev != NULL)
                prev->right = curr;

            prev = curr;
            curr = curr->right;
        }

        else
        {
            BinaryTreeNode<int>* temp = curr->left;

            while (temp->right && temp->right != curr)
                temp = temp->right;

            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }

            else
            {
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
        }
    }

    return head;
}