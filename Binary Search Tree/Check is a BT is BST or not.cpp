// using recursion
bool recur(BinaryTreeNode<int>*root, int lb, int ub) {
    if(!root) return true;
    if(root->data >= lb && root->data <= ub) {
        return recur(root->left,lb,root->data) && recur(root->right,root->data,ub);
    }
    return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return recur(root,INT_MIN,INT_MAX);
}
