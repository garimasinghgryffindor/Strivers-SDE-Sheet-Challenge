// using inorder traversal
// TC: O(N)
// SC: O(N)
void inOrder(TreeNode<int>*node, vector<int>&res) {
    if(!node) return;
    
    inOrder(node->left,res);
    res.push_back(node->data);
    inOrder(node->right,res);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int>inorder;
    inOrder(root,inorder);
    int n = inorder.size();
    if(k > n) {
        return -1;
    }
    return inorder[n-k];
}
