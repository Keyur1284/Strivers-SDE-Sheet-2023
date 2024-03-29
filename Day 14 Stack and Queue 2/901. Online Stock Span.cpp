// Problem Link :- https://leetcode.com/problems/online-stock-span/

// Solved using vector
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class StockSpanner {
public:

    vector<int> stocks;

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        stocks.emplace_back(price);

        int i = stocks.size() - 1, count = 0;

        while (i >= 0 && stocks[i] <= price)
        {
            i--;
            count++;
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */



// Solved using stack
// Time Complexity :- O(1)
// Space Complexity :- O(n);

class StockSpanner {
public:

    stack<pair<int, int>> stocks;

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int ans = 1;

        while(!stocks.empty() && stocks.top().first <= price)
        {
            ans += stocks.top().second;
            stocks.pop();
        }

        stocks.emplace(price, ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */