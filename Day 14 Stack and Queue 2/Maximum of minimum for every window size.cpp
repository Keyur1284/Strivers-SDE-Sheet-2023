// Problem Link :- https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> left (n, -1), right (n, n), temp (n + 1, 0);
        stack<int> st;
        
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if (!st.empty())
                left[i] = st.top();
                
            st.emplace(i);
        }
        
        while (!st.empty())
            st.pop();
            
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if (!st.empty())
                right[i] = st.top();
                
            st.emplace(i);
        }
        
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;
            temp[len] = max(temp[len], arr[i]);
        }
        
        for (int i = n - 1; i >= 1; i--)
            temp[i] = max(temp[i], temp[i + 1]);
            
        vector<int> ans;
        
        for (int i = 1; i <= n; i++)
            ans.emplace_back(temp[i]);
            
        return ans;
    }
};