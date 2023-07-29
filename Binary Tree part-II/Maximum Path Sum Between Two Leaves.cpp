long long recur(TreeNode<int> *root, long long &res) {
    if(!root) return 0;

    long long leftSum = recur(root->left, res);
    long long rightSum = recur(root->right, res);

    if(leftSum + rightSum + root->val > res) {
        res = leftSum + rightSum + root->val;
    } 

    return root->val + max(leftSum,rightSum);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
     if(!root || !root->left || !root->right ){
        return -1;
    }
    long long res = 0;
    // recursion
    recur(root,res);
    
    return res;
}
