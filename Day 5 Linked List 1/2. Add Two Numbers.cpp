// Problem Link :- https://leetcode.com/problems/add-two-numbers/

// Solved by traversing linked list
// Time Complexity : O(max(m,n)) where m and n are the length of the linked lists
// Space Complexity : O(max(m,n)) where m and n are the length of the linked lists

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = carry;
            
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(digit);
            temp = temp->next;
        }

        return head->next;
    }
};
