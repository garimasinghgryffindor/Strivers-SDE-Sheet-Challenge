// one way -> mirror the tree and then compare
BinaryTreeNode<int>* createMirror(BinaryTreeNode<int>*root) {
    if(!root) return NULL;
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
    newNode->left = createMirror(root->right);
    newNode->right = createMirror(root->left);
    return newNode;
}

bool compare(BinaryTreeNode<int>*root, BinaryTreeNode<int>*root2) {
    if(!root && !root2) return true;
    if(!root) return false;
    if(!root2) return false;
    if(root->data != root2->data) return false;

    return compare(root->left,root2->left) && compare(root->right, root2->right);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>*mirror = createMirror(root);

    // compare
    return compare(root, mirror);
}
