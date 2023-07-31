// RECURSIVELY
void recur(TreeNode<int>*root, int x, int&res) {
    if(!root) return;
    if(root->val <= x) {
        res = root->val;
        recur(root->right,x,res);
        return;
    }
    recur(root->left,x,res);
}
int floorInBST(TreeNode<int> * root, int X)
{
    int res = -1;
    recur(root,X,res);
    return res;
}


// ITERATIVELY
int floorInBST(TreeNode<int> * root, int x)
{
    int res = -1;
    TreeNode<int>*node = root;
    while(node) {
        if(node->val == x) {
            res = x;
            return res;
        }
        if(node->val < x) {
            res = node->val;
            node = node->right;
        } else {
            node = node->left;
        }
    }

    return res;
}
