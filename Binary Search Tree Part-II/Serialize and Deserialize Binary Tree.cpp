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




class Codec {
public:
    
string serialize(TreeNode* root) {
    if(!root) {
     return "NULL,";
    }
    return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    queue<string> q;
    string s;
    for(int i=0;i<data.size();i++)
    {
        if(data[i]==',')
        {
            q.push(s);
            s="";
            continue;
        }
        s+=data[i];
    }
    if(s.size()!=0)q.push(s);
    return deserialize_helper(q);
}

TreeNode* deserialize_helper(queue<string> &q) {
    string s=q.front();
    q.pop();
    if(s=="NULL")return NULL;
    TreeNode* root=new TreeNode(stoi(s));
    root->left=deserialize_helper(q);
    root->right=deserialize_helper(q);
    return root;
}
};
