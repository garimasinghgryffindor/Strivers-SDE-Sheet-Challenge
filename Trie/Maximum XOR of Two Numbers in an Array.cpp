// using BRUTE FORCE
int findMaximumXOR(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int temp = nums[i] ^ nums[j];
            res = max(res, temp);
        }
    }
    return res;
}



// using TRIE  &  BIT MANIPULATION
struct Node {
    Node * links[2];
    bool flag = false;
};

class Trie {
    public:
    Node * root;
    Trie() { root = new Node(); }
    void insert(int num) {
        Node * node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->links[bit]) {
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }
    }
    
    int findMaxXOR(int num) {
        int res = 0;
        Node * node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->links[!bit]) {
                res = res | (1 << i);
                node = node->links[!bit];
            } else {
                node = node->links[bit];
            }
        }
        return res;
    }
};

class Solution {
public:
    // using TRIE
    // creating a Trie data structure
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int x: nums) trie.insert(x);
        int res = 0;
        for(int x: nums) {
            int temp = trie.findMaxXOR(x);
            res = max(res, temp);
        }
        return res;
    }
};


