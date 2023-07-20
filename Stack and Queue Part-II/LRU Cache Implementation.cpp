#include <bits/stdc++.h>

// my first approach
// using queues
class LRUCache
{
public:
    unordered_map<int,int>mp;
    queue<int>lru;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        queue<int>temp;
        while(!lru.empty() && lru.front()!=key) {
            int tp = lru.front();
            lru.pop();
            temp.push(tp);
        }
        if(!lru.empty()) {
            lru.pop();
            while(!lru.empty()) {
                int tp = lru.front();
                lru.pop();
                temp.push(tp);
            }
            while(!temp.empty()) {
                lru.push(temp.front());
                temp.pop();
            }
        }
        lru.push(key);

        return mp[key];
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) {
            // update the value
            mp[key] = value;
            queue<int>temp;
            while(!lru.empty() && lru.front()!=key) {
                int tp = lru.front();
                lru.pop();
                temp.push(tp);
            }
            if(!lru.empty()) {
                lru.pop();
                while(!lru.empty()) {
                    int tp = lru.front();
                    lru.pop();
                    temp.push(tp);
                }
                while(!temp.empty()) {
                    lru.push(temp.front());
                    temp.pop();
                }
            }
            lru.push(key);
            
            return;
        }\
        if(lru.size() == size) {
            // we need to pop
            int key_last = lru.front();
            lru.pop();
            mp.erase(key_last);
            mp[key] = value;
            lru.push(key);
        } else {
            // simply push
            mp[key] = value;
            lru.push(key);
        }
    }
};



