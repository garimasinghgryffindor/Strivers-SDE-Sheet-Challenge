// using level order traversal
void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*>q;
    // root->next = NULL;
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        BinaryTreeNode<int>* top = q.front();
        q.pop();

        if(top->left) {
            q.push(top->left);
        }
        if(top->right) {
            q.push(top->right);
        }

        for(int i=0 ; i<n-1 ; i++) {
            BinaryTreeNode<int>* nxt = q.front();
            q.pop();
            top->next = nxt;
            top = nxt;

            if(top->left) {
            q.push(top->left);
            }
            if(top->right) {
                q.push(top->right);
            }
        }
        top->next = NULL;
    }
    
}
