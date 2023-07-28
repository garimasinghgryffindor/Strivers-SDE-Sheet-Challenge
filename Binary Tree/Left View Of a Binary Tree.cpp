// FIRST APPROACH
// using PREORDER
void preorder(TreeNode<int> *node, vector<int>&res, int level) {
    if(!node) {
        return;
    }
    
    if(res.size() == level) {
        res.push_back(node->data);
    }
    preorder(node->left, res, level+1);
    preorder(node->right, res, level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>res;
    // let's use preorder traversal
    // but i should also be knowing the level right?
    preorder(root, res, 0);
    return res;
}
