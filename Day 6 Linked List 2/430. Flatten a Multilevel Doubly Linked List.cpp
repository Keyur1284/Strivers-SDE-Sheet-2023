// Problem Link :- https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* DFS (Node* node, Node* rest)
    {
        if (node == NULL) 
            return rest;

        Node* nextNode = DFS(node->next, rest);
        node->next = DFS(node->child, nextNode);

        if (node->next) 
            node->next->prev = node;
        
        node->child = NULL;
        return node;
    }

    Node* flatten(Node* head) {
        
        Node* ans = DFS (head, NULL);
        return ans;
    }
};