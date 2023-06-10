// Problem Link :- https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Solved by Recursive Approach 
// Time Complexity :- O(n)
// Space Complexity :- O(n) (Stack Space)

// Merging Recursively

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge (Node* node1, Node* node2)
{
    if (node1 == NULL)
        return node2;
        
    if (node2 == NULL)
        return node1;
        
    Node* root = NULL;
        
    if (node1->data < node2->data)
    {
        root = node1;
        root->bottom = merge (node1->bottom, node2);
    }
    
    else
    {
        root = node2;
        root->bottom = merge (node1, node2->bottom);
    }
    
    return root;
}
    
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;
        
    root->next = flatten (root->next);
    root = merge (root, root->next);
    
    return root;
}



// Merging Iteratively

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge (Node* node1, Node* node2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    
    while (node1 && node2)
    {
        if (node1->data < node2->data)
        {
            temp->bottom = node1;
            temp = temp->bottom;
            node1 = node1->bottom;
        }
        
        else
        {
            temp->bottom = node2;
            temp = temp->bottom;
            node2 = node2->bottom;
        }
    }
    
    if (node1)
        temp->bottom = node1;
        
    else if (node2)
        temp->bottom = node2;
    
    return dummy->bottom;
}
    
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;
        
    root->next = flatten (root->next);
    root = merge (root, root->next);
    
    return root;
}



// Solved by using priority_queue
// Time Complexity - O(nlogn)
// Space Complexity - O(n)



/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

struct comp 
{
    bool operator () (Node *a, Node* b)
    {
        return a->data > b->data;
    }
};
    
Node *flatten(Node *root)
{
    priority_queue<Node*, vector<Node*>, comp> nodes;
    nodes.emplace(root);
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    
    while (!nodes.empty())
    {
        auto node = nodes.top();
        Node* curr = new Node(node->data);
        temp->bottom = curr;
        temp = temp->bottom;
        nodes.pop();
       
        if (node->next)
            nodes.emplace(node->next);
            
        if (node->bottom)
            nodes.emplace(node->bottom);
    }
    
    return dummy->bottom;
}