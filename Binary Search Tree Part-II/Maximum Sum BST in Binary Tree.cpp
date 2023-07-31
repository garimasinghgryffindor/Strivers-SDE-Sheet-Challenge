/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class info {
    public:
    int mini;
    int maxi;
    bool isBST;
    int sum;
};

class Solution {
public:
    info recur(TreeNode * root, int&res) {
        if(!root) return {INT_MAX, INT_MIN, true, 0};
        
        info left = recur(root->left, res);
        info right = recur(root->right, res);
        
        info curr;
        curr.mini = min(left.mini, root->val);
        curr.maxi = max(right.maxi, root->val);
        curr.sum = root->val + left.sum + right.sum;
        
        if(left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini) {
            // is a valid BST
            curr.isBST = true;
        } else {
            curr.isBST = false;
        }
        
        if(curr.isBST) res = max(res, curr.sum);
        
        return curr;
    }
    
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        recur(root,sum);
        return sum;
    }
};
