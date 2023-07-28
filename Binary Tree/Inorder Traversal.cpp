// LEFT  -> NODE ->  RIGHT
// using recursion
void inorder(TreeNode* node, vector<int>&res) {
    if(node == NULL) {
        return ;
    }

    inorder(node->left,res);
    res.push_back(node->data);
    inorder(node->right,res);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>res;
    inorder(root, res);
    return res;
}
