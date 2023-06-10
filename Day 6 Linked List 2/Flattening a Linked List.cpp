// Problem Link :- https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Time Complexity :- O(n)
// Space Complexity :- O(n)

Node* merge(Node* a, Node* b)
{
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    
    Node* ans = NULL;
    
    if(a->data < b->data)
    {
        ans = a;
        ans->bottom = merge(a->bottom, b);
    }
    else
    {
        ans = b;
        ans->bottom = merge(a, b->bottom);
    }
    
    ans->next = NULL;
    return ans;
}

Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL)
        return root;
    
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}
