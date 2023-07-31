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



// using inorder traversal
// TC: O(N)
// SC: O(1)
bool inOrder(TreeNode<int>*node, int&k, int&res) {
    if(!node) return false;
    
    bool r1 = inOrder(node->right,k,res);
    if(r1) return true;

    k--;
    if(k == 0) {
        res = node->data;
        return true;
    }

    bool l1 = inOrder(node->left,k,res);
    return l1;
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int res = -1;
    bool ans = inOrder(root,k,res);
    return res;
}
