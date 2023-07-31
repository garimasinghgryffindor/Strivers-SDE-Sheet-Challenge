void recur(BinaryTreeNode<int>*node,int x,int &res) {
    if(!node) return;
    if(node->data >= x) {
        res = node->data;
        recur(node->left,x,res);
        return;
    }
    recur(node->right,x,res);
}

int findCeil(BinaryTreeNode<int> *node, int x){
    int res = -1;
    recur(node,x,res);
    return res;
}
