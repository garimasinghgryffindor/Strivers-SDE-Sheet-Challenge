int recur(BinaryTreeNode<int>*root, bool&ans) {
    if(!root) return 0;
    if(ans == false) return 0;

    int leftHeight = recur(root->left, ans);
    int rightHeight = recur(root->right, ans);

    if(abs(leftHeight - rightHeight) > 1) {
        ans = false;
    }

    if(abs(leftHeight - rightHeight) > 1) {
        ans = false;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool ans = true;
    recur(root, ans);
    return ans;
}
