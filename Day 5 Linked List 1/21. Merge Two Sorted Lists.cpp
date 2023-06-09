// Problem Link :- https://leetcode.com/problems/merge-two-sorted-lists/

// Solved by Recursive Approach
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists (list1->next, list2);
            return list1;
        }

        else
        {
            list2->next = mergeTwoLists (list1, list2->next);
            return list2;
        }
    }
};



// Solved by Iterative Approach     (Creating another linked list)
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            
            temp = temp->next;
        }
        
        if (list1)
            temp->next = list1;
        
        if (list2)
            temp->next = list2;
        
        return head->next;
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;
        
        ListNode* head = NULL, *curr = NULL;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                if (head == NULL)
                    curr = head = list1;

                else
                {
                    curr->next = list1;
                    curr = curr->next;
                }
                
                list1 = list1->next;
            }

            else
            {
                if (head == NULL)
                    curr = head = list2;

                else
                {
                    curr->next = list2;
                    curr = curr->next;
                }

                list2 = list2->next;
            }
        }

        if (list1)
            curr->next = list1;

        if (list2)
            curr->next = list2;

        return head;
    }
};



// Solved by Iterative Approach     (Using same linked list)
// Time Complexity :- O(n + m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);
        
        ListNode* head = list1;

        while (list1 && list2)
        {
            ListNode* temp = NULL;

            while (list1 && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }

            temp->next = list2;
            swap(list1, list2);
        }

        return head;
    }
};