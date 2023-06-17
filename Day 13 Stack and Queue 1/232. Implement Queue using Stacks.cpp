// Problem Link :- https://leetcode.com/problems/implement-queue-using-stacks/

// Solved using two stacks
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class MyQueue {
public:

    stack<int> st1, st2;
    int frontEle;

    MyQueue() {
        
        frontEle = -1;
    }
    
    void push(int x) {
        
        if (st1.empty())
            frontEle = x;

        st1.emplace(x);
    }
    
    int pop() {
        
        while (st1.size() > 1)
        {
            frontEle = st1.top();
            st2.emplace(frontEle);
            st1.pop();
        }

        int ans = st1.top();
        st1.pop();

        while (!st2.empty())
        {
            st1.emplace(st2.top());
            st2.pop();
        }

        return ans;
    }
    
    int peek() {
        
        return frontEle;
    }
    
    bool empty() {
        
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



// Amortized Solution
// Time Complexity :- O(1)
// Space Complexity :- O(n)

class MyQueue {
public:

    stack<int> input, output;

    MyQueue() {
        
    }
    
    void push(int x) {
        
        input.emplace(x);
    }
    
    int pop() {
        
        if (output.empty())
        {
            while(!input.empty())
            {
                output.emplace(input.top());
                input.pop();
            }
        }

        int ans = output.top();
        output.pop();

        return ans;
    }
    
    int peek() {
        
        if (output.empty())
        {
            while(!input.empty())
            {
                output.emplace(input.top());
                input.pop();
            }
        }

        return output.top();
    }
    
    bool empty() {
        
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */