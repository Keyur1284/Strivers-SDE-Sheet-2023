// Problem Link :- https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Solved by reverse level order traversal
// Time Complexity :- O(N)
// Space Complexity :- O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == NULL)
            return root;

        queue<Node*> levelOrder;
        levelOrder.emplace(root);

        while (!levelOrder.empty())
        {
            int size = levelOrder.size();
            Node* prev = NULL;

            while (size--)
            {
                Node* node = levelOrder.front();
                levelOrder.pop();

                node->next = prev;
                prev = node;

                if (node->right)
                    levelOrder.emplace(node->right);

                if (node->left)
                    levelOrder.emplace(node->left);
            }
        }

        return root;
    }
};



// Solved by DFS
// Time Complexity :- O(N)
// Space Complexity :- O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == NULL)
            return root;

        Node* left = root->left, *right = root->right, *next = root->next;

        if (left)
        {
            left->next = right;

            if (next)
            {
                right->next = next->left;
            }

            connect (root->left);
            connect (root->right);
        }

        return root;
    }
};



// Solved by BFS (Space Optimized)
// Time Complexity :- O(N)
// Space Complexity :- O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        Node* level = root;

        while (level)
        {
            Node* curr = level;

            while (curr)
            {
                if (curr->left)
                {
                    curr->left->next = curr->right;

                    if (curr->next)
                    {
                        curr->right->next = curr->next->left;
                    }

                    curr = curr->next;
                }

                else
                    break;
            }

            level = level->left;
        }

        return root;
    }
};