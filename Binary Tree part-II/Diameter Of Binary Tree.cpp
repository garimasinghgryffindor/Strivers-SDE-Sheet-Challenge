int recur(TreeNode<int>*root,int&res) {
    if(!root) return 0;
    int leftHeight = recur(root->left, res);
    int rightHeight = recur(root->right, res);
    int maxHeight = leftHeight + rightHeight;
    if(res < maxHeight) res = maxHeight;

    return 1 + max(leftHeight,rightHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// leftmax height + rightmax height
    // let us use recursion
    int res = 0;
    recur(root,res);
    return res;
}
