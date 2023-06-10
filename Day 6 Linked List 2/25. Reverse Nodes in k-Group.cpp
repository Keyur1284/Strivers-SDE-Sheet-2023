// Problem Link :- https://leetcode.com/problems/reverse-nodes-in-k-group/

// Solved by Recursive Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n/k) (Stack Space)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        int count = 0;

        while (curr && count != k)
        {
            count++;
            curr = curr->next;
        }

        if (count == k)
        {
            curr = reverseKGroup (curr, k);

            while (count--)
            {
                ListNode* nextNode = head->next;
                head->next = curr;
                curr = head;
                head = nextNode;
            }

            head = curr;
        }

        return head;
    }
};

// Solved by Iterative Approach
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

    int countNodes (ListNode* node)
    {
        int count = 0;

        while (node)
        {
            count++;
            node = node->next;
        }

        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int nodes = countNodes (head);
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* prevNode = dummyNode, *firstNode, *nextNode;

        while (nodes >= k)
        {
            firstNode = prevNode->next;
            nextNode = firstNode->next;

            for (int i = 1; i < k; i++)
            {
                firstNode->next = nextNode->next;
                nextNode->next = prevNode->next;
                prevNode->next = nextNode;
                nextNode = firstNode->next;
            }

            prevNode = firstNode;
            nodes -= k;
        }

        return dummyNode->next;
    }
};