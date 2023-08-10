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
