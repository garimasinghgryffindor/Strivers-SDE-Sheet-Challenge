// using bfs
// maximum width of a level
int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int res = 0;

    while(!q.empty()) {
        int n = q.size();
        res = max(res, n);
        for(int i=0 ; i<n ; i++) {
            auto ptr = q.front();
            q.pop();
            if(ptr->left) {
                q.push(ptr->left);
            }
            if(ptr->right) {
                q.push(ptr->right);
            }
        }
    }

    return res;
}
