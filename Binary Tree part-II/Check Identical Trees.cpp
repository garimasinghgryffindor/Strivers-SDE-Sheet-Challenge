// RECURSION
// DFS
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // let us use recursion
    if(!root1 && !root2) return true;
    if(!root1) return false;
    if(!root2) return false;
    if(root1->data != root2->data) return false;
    
    bool left = identicalTrees(root1->left, root2->left);
    if(!left) return false;
    bool right = identicalTrees(root1->right, root2->right);
    if(!right) return false;

    return true;
}
