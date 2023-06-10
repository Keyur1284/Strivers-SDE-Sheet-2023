// Problem Link :- https://leetcode.com/problems/intersection-of-two-linked-lists/

// Solved using unordered_set
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> vis;

        while (headA || headB)
        {
            if (headA)
            {
                if (vis.find(headA) != vis.end())
                    return headA;

                vis.emplace(headA);
                headA = headA->next;
            }

            if (headB)
            {
                if (vis.find(headB) != vis.end())
                    return headB;
                
                vis.emplace(headB);
                headB = headB->next;
            }
        }

        return NULL;
    }
};



// Time Complexity :- O(n + m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> vis;

        while (headA)
        {
            vis.emplace(headA);
            headA = headA->next;
        }

        while (headB)
        {
            if (vis.find(headB) != vis.end())
                return headB;

            headB = headB->next;
        }

        return NULL;
    }
};


// Solved using two pointers
// Time Complexity :- O(n + m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* currA = headA, *currB = headB;

        while (currA != currB)
        {
            currA = (currA) ? currA->next : headB;
            currB = (currB) ? currB->next : headA;
        }

        return currA;
    }
};



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

    int getDiff (ListNode *headA, ListNode *headB)
    {
        int diff = 0;

        while (headA || headB)
        {
            if (headA)
            {
                diff++;
                headA = headA->next;
            }

            if (headB)
            {
                diff--;
                headB = headB->next;
            }
        }

        return diff;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int diff = getDiff (headA, headB);

        if (diff < 0)
        {
            diff *= -1;
            swap(headA, headB);
        }

        while(diff--)
            headA = headA->next;

        while (headA != headB)
        {
            if (headA)
                headA = headA->next;

            if (headB)
                headB = headB->next;
        }

        return headA;
    }
};