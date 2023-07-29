vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // let us use deque
    if(!root) return {};
    vector<int>res;
    deque<BinaryTreeNode<int>*>dq;
    dq.push_back(root);
    bool odd = true;
    while(!dq.empty()) {
        int n = dq.size();
        for(int i=0 ; i<n ; i++) {
            if(odd) {
                auto ptr = dq.front();
                dq.pop_front();
                res.push_back(ptr->data);
                if(ptr->left) {
                    dq.push_back(ptr->left);
                }
                if(ptr->right) {
                    dq.push_back(ptr->right);
                }
            } else {
                auto ptr = dq.back();
                dq.pop_back();
                res.push_back(ptr->data);
                if(ptr->right) {
                    dq.push_front(ptr->right);
                }
                if(ptr->left) {
                    dq.push_front(ptr->left);
                }
            }
        }
        odd = !odd;
    }

    return res;
}
