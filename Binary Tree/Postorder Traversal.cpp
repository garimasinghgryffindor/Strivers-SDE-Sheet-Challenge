// LEFT  ->  RIGHT  ->  NODE
// using RECURSION
void postorder(TreeNode *node, vector<int>&res) {
    if(!node)
        return;
    
    postorder(node->left, res);
    postorder(node->right, res);
    res.push_back(node->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>res;
    postorder(root, res);
    return res;
}
