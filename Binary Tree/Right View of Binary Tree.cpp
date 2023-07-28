// using RECURSION
class Solution {
public:
    void recur(TreeNode*node, vector<int>&res,int level) {
        if(!node)
            return;
        if(res.size() == level) {
            res.push_back(node->val);
        }
        recur(node->right, res, level+1);
        recur(node->left, res, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recur(root, res, 0);
        return res;
    }
};


// using LEVEL ORDER TRAVERSAL 
// BFS
class Solution {
public:
    void bfs(TreeNode*node, vector<int>&res) {
        if(!node)
            return;
        
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty()) {
            int tp = q.front()->val;
            res.push_back(tp);
            int n = q.size();
            for(int i=0 ; i<n ; i++) {
                TreeNode *ptr = q.front();
                if(ptr->right) {
                    q.push(ptr->right);
                }
                if(ptr->left) {
                    q.push(ptr->left);
                }
                q.pop();
            }
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        bfs(root, res);
        return res;
    }
};
