#include <bits/stdc++.h> 
class LFUCache
{
public:
    unordered_map<int,pair<int,int> > cache;
    unordered_map<int, list<int> > freq;
    unordered_map<int, list<int>::iterator > pos;
    int minFreq;
    int size;
    LFUCache(int capacity)
    {
        size = capacity;
        minFreq = 0;
    }

    int get(int key)
    {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if(cache.find(key) != cache.end()) {
            // already exists
            // need to update
            int prevFreq = cache[key].second;
            cache[key] = {value, prevFreq+1};
            auto position = pos[key];
            freq[prevFreq].erase(position);
            freq[prevFreq+1].push_front(key);
            pos.erase(key);
            pos[key] = freq[prevFreq+1].begin();

            if(freq[minFreq].empty()) {
                minFreq++;
            }
            
        } else {
            if(size == cache.size()) {
                // cache is full
                // need to remove lfu
                int lfu = freq[minFreq].back();
                cache.erase(lfu);
                freq[minFreq].pop_back();
                pos.erase(lfu);
            }

            // simply push new key-value pair
            cache[key] = {value, 1};
            freq[1].push_front(key);
            pos[key] = freq[1].begin();
            minFreq = 1;
        }
    }
};
