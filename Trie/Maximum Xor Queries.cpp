// APPROACH 1 -> The obvious Brute Force approach

// APPROACH 2 -> Brute Force using Trie and Bit Manipulation
struct Node {
    Node *links[2];
};

class Solution {
public:
    Node * root;
    
    void insert(int num) {
        Node * node = root;
        for(int i = 31; i >= 0; i--) {
            int LMbit = (num >> i) & 1;
            if(!node->links[LMbit]) {
                node->links[LMbit] = new Node();
            }
            node = node->links[LMbit];
        }
    }
    
    int maxXor(int num) {
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
    
    // BRUTE FORCE
    // APPLYING THE TRIE AND BIT MANIPULATION SOLUTION FOR EACH ELEMENT IN THE QUERY less than equal to mi
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        int q = queries.size();
        for(int i = 0; i < q; i++) {
            root = new Node();
            int val = queries[i][0];
            int thresh = queries[i][1];
            bool flag = false;
            for(int x: nums) {
                if(x <= thresh) {
                    insert(x);
                    flag = true;
                }
            }
            if(!flag) { res.push_back(-1); continue; }
            int ans = maxXor(val);
            res.push_back(ans);
        }
        
        return res;
    }
};



// APPROACH 3
// OPTIMAL TRIE AND BIT MANIPULATION USING SORTING AND OFFLINE QUERIES
// APPLYING THE TRIE AND BIT MANIPULATION SOLUTION for OFFLINE QUERIES
// i.e.; we will be creating only 1 trie;
// and sort the queries in increasing order as per the mi
struct Node {
    Node *links[2];
};

class Solution {
public:
    Node * root;
    
    void insert(int num) {
        Node * node = root;
        for(int i = 31; i >= 0; i--) {
            int LMbit = (num >> i) & 1;
            if(!node->links[LMbit]) {
                node->links[LMbit] = new Node();
            }
            node = node->links[LMbit];
        }
    }
    
    int maxXor(int num) {
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

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int>res(q,0);
        root = new Node();
        vector<vector<int>>vec;
        for(int i = 0; i < q; i++) {
            vec.push_back({queries[i][1], queries[i][0], i});
        }
        
        sort(vec.begin(), vec.end());
        sort(nums.begin(), nums.end());
        
        bool flag = false;
        int idx = 0;
        for(int i = 0; i < q; i++) {
            int val = vec[i][1];
            int thresh = vec[i][0];
            int actualIndx = vec[i][2];
            for(idx; idx < nums.size() && nums[idx] <= thresh ; idx++) {
                if(nums[idx] <= thresh) {
                    insert(nums[idx]);
                    flag = true;
                }
            }
            if(!flag) { res[actualIndx] = -1; continue; }
            int ans = maxXor(val);
            res[actualIndx] = ans;
        }
        
        return res;
    }
};
