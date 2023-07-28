// NODE  ->  LEFT  ->  RIGHT 
// using RECURSION 
void preorder(TreeNode* node, vector<int>&res) {
    if(!node) {
        return;
    }
    res.push_back(node->data);
    preorder(node->left, res);
    preorder(node->right, res);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>res;
    preorder(root, res);
    return res;
}
