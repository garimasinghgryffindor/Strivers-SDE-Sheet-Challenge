vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>res;
    queue<BinaryTreeNode<int> * > q;
    if(!root) return res;

    q.push(root);
    
    while(!q.empty()) {
        auto tp = q.front(); q.pop();
        res.push_back(tp->val);
        
        if(tp->left) {
            q.push(tp->left);
        }
        if(tp->right) {
            q.push(tp->right);
        }
    }

    return res;
}
