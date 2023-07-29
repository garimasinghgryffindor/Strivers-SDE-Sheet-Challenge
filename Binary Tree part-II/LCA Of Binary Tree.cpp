// my approach
// using dfs
// Not Optimal
bool recur(TreeNode<int>*root, int x) {
    if(!root) return false;
    if(root->data == x) return true;

    return (recur(root->left,x) || recur(root->right, x) );
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(!root) return -1;
    if(root->data == x) {
        if(recur(root->left, y)) {
            return root->data;
        }
        if(recur(root->right,y)) {
            return root->data;
        }
    }

    if(root->data == y) {
        if(recur(root->left, x)) {
            return root->data;
        }
        if(recur(root->right,x)) {
            return root->data;
        }
    }

	if((recur(root->left, x) && recur(root->right, y)) || (recur(root->left,y) && recur(root->right,x))) {
        return root->data;
    }

    if(recur(root->left,x) && recur(root->left, y)) {
        return lowestCommonAncestor(root->left, x, y);
    }
    
    return lowestCommonAncestor(root->right, x, y);
}



// OPTIMAL APPROACH
// USING RECURSION
TreeNode<int>* recur(TreeNode<int>* root, int x, int y) {
    if(!root) return NULL;
    if(root->data == x || root->data == y)
        return root;
    
    auto left = recur(root->left,x,y);
    auto right = recur(root->right,x,y);
    if(left && right) {
        return root;
    }

    if(left) {
        return left;
    }
    if(right) {
        return right;
    }
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    auto node = recur(root,x,y);
    return node->data;
}




