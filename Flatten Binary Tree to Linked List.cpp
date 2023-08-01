// APPROACH 1
// USING QUEUE TO STORE THE INORDER
void inorder(BinaryTreeNode<int>*root, queue<int>&q) {
    if(!root) return;
    inorder(root->left, q);
    q.push(root->data);
    inorder(root->right, q);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    queue<int>q;
    inorder(root,q);
    BinaryTreeNode<int> * dummy = new BinaryTreeNode<int>(0);
    BinaryTreeNode<int> * curr = dummy;
    while(!q.empty()) {
        curr->right = new BinaryTreeNode<int>(q.front());
        q.pop();
        curr->left = NULL;
        curr = curr->right;
    }

    return dummy->right;
}
