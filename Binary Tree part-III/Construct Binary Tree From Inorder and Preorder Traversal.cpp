int search(vector<int> arr, int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

TreeNode<int> *recur(vector<int>inorder,vector<int>preorder,int l,int r,int&preIndex) {
    if(l > r || preIndex>=preorder.size()) return NULL;

    int val = preorder[preIndex++];
    TreeNode<int>* node = new TreeNode<int>(val);

    int idx = search(inorder,l,r,val);
    
    node->left = recur(inorder,preorder,l,idx-1,preIndex);
    node->right = recur(inorder,preorder,idx+1,r,preIndex);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();
    int index = 0;
	return recur(inorder, preorder,0,n-1,index);
}
