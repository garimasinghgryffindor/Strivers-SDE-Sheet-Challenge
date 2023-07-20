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


// OPTIMAL
// USING DLL AND MAPS
class LRUCache
{
public:
    class node {
       public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int k, int v) {
            key = k;
            val = v;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    unordered_map<int, node*> mp;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        node *ptr = mp[key];
        int val = ptr->val;
        node *nxt = ptr->next;
        node *prv = ptr->prev;
        prv->next = nxt;
        nxt->prev = prv;
        node * beforeTail = tail->prev;
        tail->prev = ptr;
        ptr->next = tail;
        beforeTail->next = ptr;
        ptr->prev = beforeTail;
        return val;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) {
            // key already exists
            // therefore we need to update the value
            node * ptr = mp[key];
            ptr->val = value;
            // also updating it's position to be the latest in the cache
            node * prv = ptr->prev;
            node * nxt = ptr->next;
            prv->next = nxt;
            nxt->prev = prv;
            node * beforeTail = tail->prev;
            tail->prev = ptr;
            ptr->next = tail;
            beforeTail->next = ptr;
            ptr->prev = beforeTail;
        } else {
            // if key not found
            // put it
            // but have to also check the capacity
            if(mp.size() == size) {
                // we need to remove lru
                node * afterHead = head->next;
                int _key = afterHead->key;
                mp.erase(_key);
                node * nxt = afterHead->next;
                head->next = nxt;
                nxt->prev = head;
                // and push new key value pair
                node * ptr = new node(key, value);
                node * beforeTail = tail->prev;
                tail->prev = ptr;
                ptr->next = tail;
                beforeTail->next = ptr;
                ptr->prev = beforeTail;
                mp[key] = ptr;
            } else {
                // simply put
                node * ptr = new node(key, value);
                node * beforeTail = tail->prev;
                tail->prev = ptr;
                ptr->next = tail;
                beforeTail->next = ptr;
                ptr->prev = beforeTail;
                mp[key] = ptr;
            }
        }
    }
};




