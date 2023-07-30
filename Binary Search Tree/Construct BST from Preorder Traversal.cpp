TreeNode<int>* recur(vector<int>&preorder, int l, int r) {
    if(l > r) return NULL;
    int rootElement = preorder[l];
    TreeNode<int>* root = new TreeNode<int>(rootElement);

    // we have to determine new range -> i.e; new l and r for left and right of the root
    int x = -1;
    for(int i=l+1 ; i<=r ; i++) {
        if(preorder[i] > rootElement) {
            x = i;
            break;
        }
    }

    if(x == -1) {
        // right subtree does not exist
        root->left = recur(preorder,l+1,r);
        root->right = recur(preorder,r+1,r);
    } else {
        root->left = recur(preorder,l+1,x-1);
        root->right = recur(preorder,x,r);
    }
    
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int n = preOrder.size();
    return recur(preOrder,0,n-1);
}


