// Problem Link :- https://leetcode.com/problems/implement-stack-using-queues/

// Solved using two queues
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class MyStack {
public:

    queue <int> q1, q2;
    int topEle;

    MyStack() {
        
        topEle = -1;
    }
    
    void push(int x) {
        
        topEle = x;
        q1.emplace(x);
    }
    
    int pop() {
        
        while (q1.size() > 1)
        {
            topEle = q1.front();
            q2.emplace(topEle);
            q1.pop();
        }

        int ans = q1.front();
        q1.pop();

        while (!q2.empty())
        {
            q1.emplace(q2.front());
            q2.pop();
        }

        return ans;
    }
    
    int top() {

        return topEle;
    }
    
    bool empty() {
        
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */



// Solved using one queue
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class MyStack {
public:

    queue <int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        
        int size = q.size();
        q.emplace(x);

        for (int i = 0; i < size; i++)
        {
            q.emplace(q.front());
            q.pop();
        }
    }
    
    int pop() {

        int top = q.front();
        q.pop();

        return top;
    }
    
    int top() {

        return q.front();
    }
    
    bool empty() {
        
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */