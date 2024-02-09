// Problem Link :- https://leetcode.com/problems/largest-rectangle-in-histogram/

// Solved using stack
// Finding next smaller element on left and right
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left (n, -1), right (n, n);
        stack <int> st;

        // Finding next smaller element in left

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                left[i] = st.top();

            st.emplace(i);
        }

        while (!st.empty())
            st.pop();

        // Finding next smaller element in right

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                right[i] = st.top();

            st.emplace(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            left[i] = (!st.empty()) ? st.top() + 1 : 0;

            st.emplace(i);
        }

        while(!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            right[i] = (!st.empty()) ? st.top() - 1 : n - 1;

            st.emplace(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int area = (right[i] - left[i] + 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};



// Solved using stack (in one pass)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size(), maxArea = 0;;
        stack <int> st;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                
                int width = i;

                if (!st.empty())
                    width = i - st.top() - 1;

                int area = height * width;
                maxArea = max (maxArea, area);
            }

            st.emplace(i);
        }

        return maxArea;
    }
};