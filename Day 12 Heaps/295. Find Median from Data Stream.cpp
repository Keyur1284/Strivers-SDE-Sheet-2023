// Problem Link :- https://leetcode.com/problems/find-median-from-data-stream/

// Solved using multiset
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class MedianFinder {
public:

    multiset<int> nums;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        nums.emplace(num);
    }
    
    double findMedian() {
        
        int size = nums.size();
        int mid = size/2;

        auto it = nums.begin();
        advance(it, mid);

        double median = *it;

        if (size % 2 == 0)
        {
            it = prev(it);
            median += *it;
            median /= 2.0;
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



// Solved using priority_queue
// Time Complexity :- O(logn)
// Space Complexity :- O(n)

class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if (maxHeap.empty() || maxHeap.top() > num)
            maxHeap.emplace(num);

        else
            minHeap.emplace(num);

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        }

        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        
        if (maxHeap.size() == minHeap.size())
        {
            return ((maxHeap.top() + minHeap.top())/2.0);
        }

        else if (maxHeap.size() > minHeap.size())
            return maxHeap.top();

        else
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */