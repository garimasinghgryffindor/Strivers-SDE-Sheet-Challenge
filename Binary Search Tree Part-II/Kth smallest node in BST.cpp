// approach 1 
// calculating the inorder
// and the returning the kth element
// TC: O(N)
// SC: O(N)
void inOrder(TreeNode<int>*node, vector<int>&res) {
    if(!node) return;
    inOrder(node->left,res);
    res.push_back(node->data);
    inOrder(node->right,res);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	vector<int>inorder;
    inOrder(root,inorder);
    return inorder[k-1];
}



// approach 2 
// calculating the inorder
// and the returning the kth element
// TC: O(N)
// SC: O(1)
void inorder(TreeNode<int>*node, int &k,int &res) {
    if(!node) return;

    inorder(node->left,k,res);

    k--;
    if(k == 0) {
        res = node->data;
        return;
    }

    inorder(node->right,k,res);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int res = -1;
    inorder(root,k,res);
    return res;
}



// approach 3 
// calculating the inorder
// and the returning the kth element
// TC: O(N)
// SC: O(1)
bool inorder(TreeNode<int>*node, int &k,int &res) {
    if(!node) return false;

    bool l1 = inorder(node->left,k,res);
    if(l1 == true) {
        return true;
    }

    k--;
    if(k == 0) {
        res = node->data;
        return true;
    }

    bool r1 = inorder(node->right,k,res);
    return r1;
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int res = -1;
    inorder(root,k,res);
    return res;
}
