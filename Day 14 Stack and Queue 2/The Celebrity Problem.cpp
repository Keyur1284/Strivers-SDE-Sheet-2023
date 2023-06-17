// Problem Link :- https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// Solve by brute force approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& peeps, int n) 
    {
        for (int col = 0; col < n; col++)
        {
            int sum = 0;
            
            for (int row = 0; row < n; row++)
            {
                sum += peeps[row][col];
            }
            
            if (sum == n - 1)
            {
                sum = 0;
                
                for (int i = 0; i < n; i++)
                    sum += peeps[col][i];
                
                if (sum == 0)
                    return col;
            }
        }
        
        return -1;
    }
};



// Solve using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& peeps, int n) 
    {
        stack<int> st;
        
        for (int i = 0; i < n; i++)
            st.emplace(i);
        
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if (peeps[a][b] == 1)
                st.emplace(b);
                
            else
                st.emplace(a);
        }
        
        int ans = st.top();
        st.pop();
        
        for (int i = 0; i < n; i++)
        {
            if (i != ans && (peeps[i][ans] == 0 || peeps[ans][i] == 1))
                return -1;
        }
        
        return ans;
    }
};



// Solve using two pointer
// Time Complexity :- O(n)
// Space Complexity :- O(1)

//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& peeps, int n) 
    {
        int i = 0, j = n - 1;
        
        while (i < j)
        {
            if (peeps[i][j])
                i++;
                
            else
                j--;
        }
        
        for (int k = 0; k < n; k++)
        {
            if (i != k && (peeps[i][k] == 1 || peeps[k][i] == 0))
                return -1;
        }
        
        return i;
    }
};
