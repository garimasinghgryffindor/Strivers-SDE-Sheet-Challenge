// approach 1
// using set
bool recur(BinaryTreeNode<int>*root, int k, unordered_set<int>&st) {
    if(!root) return false;
    if(root->data > k) {
        // look at the lhs
        return recur(root->left, k, st);
    } else {
        if(st.find(k-root->data) != st.end()) {
            // found the pair
            return true;
        }
    }

    st.insert(root->data);
    return recur(root->left,  k, st) || recur(root->right, k, st);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int>st;
    return recur(root,k,st);
}
