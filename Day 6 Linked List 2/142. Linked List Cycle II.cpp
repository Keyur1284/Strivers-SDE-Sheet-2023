// Problem Link :- https://leetcode.com/problems/linked-list-cycle-ii/

// Solved by using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> vis;

        while (head)
        {
            if (vis.find(head) != vis.end())
                return head;
            
            vis.emplace(head);
            head = head->next;
        }

        return NULL;
    }
};



// Solved by using Floyd's Tortoise and Hare (Cycle Detection) Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* hare = head, *tortoise = head;

        while (hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (hare == tortoise)
            {
                tortoise = head;

                while (tortoise != hare)
                {
                    tortoise = tortoise->next;
                    hare = hare->next;
                }

                return tortoise;
            }
        }

        return NULL;
    }
};