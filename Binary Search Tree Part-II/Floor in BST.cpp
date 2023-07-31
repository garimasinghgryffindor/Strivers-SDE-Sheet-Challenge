// BRUTE FORCE APPROACH 
// COMPARING WITH ALL THE NODES
void recur(TreeNode<int>*root, int x, int&res) {
    if(!root) return;
    if(root->val <= x) {
        res = max(res,root->val);
        recur(root->right,x,res);
        return;
    }
    recur(root->left,x,res);
}

int floorInBST(TreeNode<int> * root, int X)
{
    int res = INT_MIN;
    recur(root,X,res);
    return res;
}
