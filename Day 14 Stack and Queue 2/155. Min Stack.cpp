// Problem Link :- https://leetcode.com/problems/min-stack/

// Solved using stack
// Time Complexity :- O(1)
// Space Complexity :- O(n)

class MinStack {
public:

    stack<pair<int, int>> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if (minStack.empty())
            minStack.emplace (val, val);

        else
            minStack.emplace (val, min(val, minStack.top().second));
    }
    
    void pop() {

        minStack.pop();
    }
    
    int top() {
        
        return minStack.top().first;
    }
    
    int getMin() {
        
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



class MinStack {
public:

    stack<int> st, minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        
        st.emplace(val);

        if (minStack.empty() || val <= getMin())
            minStack.emplace(val);
    }
    
    void pop() {

        if (st.top() == getMin())
            minStack.pop();
            
        st.pop();
    }
    
    int top() {
        
        return st.top();
    }
    
    int getMin() {
        
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



class MinStack {
public:

    long long mini;
    stack<long long> st;

    MinStack() {
        
        mini = INT_MAX;
    }
    
    void push(int val) {
        
        if (st.empty())
        {
            st.emplace(val);
            mini = val;
        }

        else
        {
            if (val < mini)
            {
                st.emplace(2LL * val - mini);
                mini = val;
            }

            else
                st.emplace(val);
        }
    }
    
    void pop() {

        if (st.top() < mini)
        {
            mini = 2LL * mini - st.top();
        }   

        st.pop();
    }
    
    int top() {
        
        if (st.top() < mini)
            return mini;

        else
            return st.top(); 
    }
    
    int getMin() {
        
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */