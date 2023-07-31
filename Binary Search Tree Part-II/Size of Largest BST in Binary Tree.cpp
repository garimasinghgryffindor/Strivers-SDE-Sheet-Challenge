class info{
public:
    int mini;
    int maxi;
    bool isBST;
    int siz;
};

info solve(TreeNode<int>* root, int &yes){
    // base case
    if(root == NULL) return {INT_MAX, INT_MIN, true, 0};

    info left = solve(root->left, yes);
    info right = solve(root->right, yes);

    info curr;
    curr.mini = min(left.mini, root->data);
    curr.maxi = max(right.maxi, root->data);
    curr.siz = left.siz + right.siz + 1;

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini) ) {
        curr.isBST = true;
    }
    else curr.isBST = false;

    if(curr.isBST == true) {yes = max(yes, curr.siz);}
    
    return curr;
}

int largestBST(TreeNode<int>* root) 
{
    int max_siz = 0;
    info temp = solve(root, max_siz);
    return max_siz;
}

