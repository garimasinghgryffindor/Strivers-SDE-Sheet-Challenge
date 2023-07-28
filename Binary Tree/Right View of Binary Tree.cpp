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
