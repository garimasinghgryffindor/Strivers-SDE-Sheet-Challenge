class Codec {
public:
    
    void recur(TreeNode*root, string&ans) {
        if (!root) {
            ans += "$";
            return;
        }
        ans += to_string(root->val)+"@";
        recur(root->left, ans);
        recur(root->right, ans);
    }
    
    string serialize(TreeNode* root) {
        // we could use $ to indicate null values
        // and store the level order traversal of smth
        // let us try using dfs
        string ans = "";
        recur(root, ans);
        return ans;
    }

    
    
    TreeNode* recur2(string s,int&idx) {
        if(idx >= s.length()) return NULL;
        if (s[idx] == '$') {
            idx++;
            return NULL;
        }

        int x = 0;
        string curr = "";
        while(s[idx]!='@') {
            curr += s[idx];
            idx++;
        }
        x = stoi(curr);
        idx++;

        TreeNode* node = new TreeNode(x);
        node->left = recur2(s,idx);
        node->right = recur2(s,idx);

        return node;
    }

    TreeNode* deserialize(string serialized) {
        int idx = 0;
        return recur2(serialized,idx);
    }
};
