// Problem Link :- https://leetcode.com/problems/lfu-cache/

// Solved using list and unordered_map
// Time Complexity :- O(1)
// Space Complexity :- O(capacity)

class LFUCache {
public:

    int storage, minFreq;
    unordered_map <int, list<pair<int, int>>> frequency;
    unordered_map <int, pair<int, list<pair<int, int>>::iterator>> cache;

    LFUCache(int capacity) {
        
        storage = capacity; 
        minFreq = 0;
    }

    void insert(int key, int freq, int value)
    {
        frequency[freq].push_back({key, value});
        cache[key] = {freq, --frequency[freq].end()};
    }
    
    int get(int key) {
        
        auto it = cache.find(key);

        if (it == cache.end())
            return -1;

        int freq = it->second.first;
        auto itr = it->second.second;
        pair<int, int> temp = *itr;

        frequency[freq].erase(itr);

        if (frequency[freq].empty() && minFreq == freq)
        {
            minFreq++;
        }

        insert(key, freq + 1, temp.second);

        return temp.second;
    }
    
    void put(int key, int value) {

        auto it = cache.find(key);

        if (it != cache.end())
        {
            it->second.second->second = value;
            get(key);
            return;
        }

        if (cache.size() == storage)
        {
            cache.erase(frequency[minFreq].front().first);
            frequency[minFreq].pop_front();
        }

        minFreq = 1;
        insert(key, 1, value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */