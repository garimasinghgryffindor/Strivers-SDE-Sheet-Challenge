// RECURSION

void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    if(root->left == NULL && root->right == NULL) return;
    if(root->left == NULL) {
        int mx = max(root->right->data, root->data);
        root->data = mx;
        root->right->data = mx;
    }
    else if(root->right == NULL) {
        int mx = max(root->left->data, root->data);
        root->data = mx;
        root->left->data = mx;
    }
    else {
        if(root->data < root->left->data + root->right->data) {
            root->data = root->left->data + root->right->data;
        } else if(root->data > root->left->data + root->right->data) {
            root->left->data = root->data - root->right->data;
        }
    }
    
    changeTree(root->left);
    changeTree(root->right);

    if(root->left == NULL) {
        int mx = max(root->right->data, root->data);
        root->data = mx;
        root->right->data = mx;
    }
    else if(root->right == NULL) {
        int mx = max(root->left->data, root->data);
        root->data = mx;
        root->left->data = mx;
    }
    else {
        if(root->data < root->left->data + root->right->data) {
            root->data = root->left->data + root->right->data;
        } else if(root->data > root->left->data + root->right->data) {
            root->left->data = root->data - root->right->data;
        }
    }
}  
