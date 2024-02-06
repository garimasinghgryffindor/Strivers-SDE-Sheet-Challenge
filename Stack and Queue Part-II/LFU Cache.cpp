class LFUCache {
public:
    unordered_map<int, list<pair<int, pair<int, int> > > > freq;
    unordered_map<int, list<pair<int, pair<int, int> > >::iterator > cache;
    int cap;
    int minFreq;
    
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        
        if(cache.find(key) == cache.end()) return -1;
        // it exists otherwise
        // you would need to update it after this
        auto it = cache[key];
        int val = (it->second).first;
        int f = (it->second).second;
        (it->second).second = f+1;
        
        freq[f+1].splice(freq[f+1].begin(), freq[f], it);
        if(f==minFreq && freq[f].size() == 0) minFreq = f+1;
        
        return val;
    }
    
    void put(int key, int value) {
        // check if it already exists
        if(cache.find(key) != cache.end()) {
            // only update
            auto it = cache[key];
            int val = (it->second).first;
            int f = (it->second).second;
            (it->second).second = f+1;
            (it->second).first = value;
            
            freq[f+1].splice(freq[f+1].begin(), freq[f], it);
            
            if(f==minFreq && freq[f].size() == 0) minFreq = f+1;
        } else {
            // if does not exists
      
            // check the capacity
            if(cap != 0) {
             
                // does not needs eviction
                // you are putting it for the first time
                // so the frequency has to be 1
                freq[1].push_front({key, {value, 1}});
                cache[key] = freq[1].begin();
                cap--;
                minFreq = 1;
                
            } else {
             
                // needs eviction
                // remove the last of the minFrequency element
                int lfu = (freq[minFreq].back()).first;
                freq[minFreq].pop_back();
                cache.erase(lfu);
                
                // insert the new element at freq = 1
                freq[1].push_front({key, {value, 1}});
                cache[key] = freq[1].begin();
                minFreq = 1;
            }
        }
    }
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
