// FIRST APPROACH
// using PREORDER
void preorder(TreeNode<int> *node, vector<int>&res, int level) {
    if(!node) {
        return;
    }
    
    if(res.size() == level) {
        res.push_back(node->data);
    }
    preorder(node->left, res, level+1);
    preorder(node->right, res, level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>res;
    // let's use preorder traversal
    // but i should also be knowing the level right?
    preorder(root, res, 0);
    return res;
}



// SECOND APPROACH
// using LEVEL ORDER TRAVERSAL
// LEVEL ORDER TRAVERSAL = BFS
void levelorder(TreeNode<int> *node, vector<int>&res) {
    if(!node) {
        return;
    }
    
    queue<TreeNode<int>* > q;
    q.push(node);

    while(!q.empty()) {
        int tp = q.front()->data;
        res.push_back(tp);
        int n = q.size();
        for(int i=0 ; i<n ; i++) {
            TreeNode<int>*curr = q.front();
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
            q.pop();
        }
    }
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>res;
    levelorder(root, res);
    return res;
}
