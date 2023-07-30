// APPROACH 1 -> NAIVE APPROACH
// SAVE THE PREORDER OF THE TREE IN THE VECTOR
// AND CREATE A LINKED LIST USING THIS VECTOR
void preorder(TreeNode<int>*root, vector<int>&res) {
    if(!root) return ;
    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);
}

TreeNode<int>* createLinkedList(vector<int>res) {
    TreeNode<int>*dummy = new TreeNode<int>(0);
    TreeNode<int>* curr = dummy;
    
    for(int i=0 ; i<res.size() ; i++) {
        TreeNode<int>* node = new TreeNode<int>(res[i]);
        curr->right = node;
        curr = curr->right;
    }
    return dummy->right;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    vector<int>pre;
    preorder(root,pre);
    return createLinkedList(pre);
}



// APPROACH 2
// WITHOUT USING EXTRA SPACE
// IN-PLACE
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root) return root;
    
    TreeNode<int>* curr = root;
    while(curr) {
        if(curr->left) {
            TreeNode<int>*pred = curr->left;
            while(pred->right) {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }

    return root;
}
