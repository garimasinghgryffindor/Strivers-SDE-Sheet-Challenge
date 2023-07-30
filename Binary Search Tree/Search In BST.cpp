bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(!root) return false;
    if(root->data == x) return true;
    if(root->data < x) {
        // search in the rhs
        return searchInBST(root->right, x);
    }
    // search in the lhs
    return searchInBST(root->left, x);
}
