// Problem Link :- https://leetcode.com/problems/reverse-linked-list/

// Iterative Solution
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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL, *curr = head;

        while (curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};


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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* newHead = NULL;

        while (head)
        {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }

        return newHead;
    }
};



// Recursive Solution
// Time Complexity :- O(n)
// Space Complexity :- O(n) (Stack Space)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};