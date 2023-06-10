// Problem Link :- https://leetcode.com/problems/rotate-list/

// Solved by traversing
// Time Complexity :- O(n)
// Space Complexity :- O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == NULL || head->next == NULL || k == 0) 
            return head;

        int nodes = 1;
        ListNode* node = head;

        while (node->next)
        {
            nodes++;
            node = node->next;
        }

        node->next = head;
        k %= nodes;

        int last = nodes - k;

        while (last--)
            node = node->next;

        head = node->next;
        node->next = NULL;

        return head;        
    }
};