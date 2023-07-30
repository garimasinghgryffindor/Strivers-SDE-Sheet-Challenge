// basic binary search approach

// REMEMBER TO SEND THE VECTOR BY REFERNCE (ADDRESS) OTHERWISE TIME COMPLEXITY WILL INCREASE, WHICH WE DON'T WONT OF'COURSE
TreeNode<int>* construct(vector<int>&arr,int l, int r) {
    if(l > r) return NULL;
    int mid = l + (r-l)/2;

    TreeNode<int>* node = new TreeNode<int>(arr[mid]);
    node->left = construct(arr,l,mid-1);
    node->right = construct(arr,mid+1,r);

    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return construct(arr,0,n-1);
}
