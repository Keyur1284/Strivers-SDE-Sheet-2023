// Problem Link :- https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        
        vector<int> ans(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() >= a[i])
                st.pop();
                
            if (!st.empty())
                ans[i] = st.top();
                
            st.emplace(a[i]);
        }
        
        return ans;
    }
};