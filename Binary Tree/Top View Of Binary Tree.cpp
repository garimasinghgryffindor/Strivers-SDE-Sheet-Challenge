// using level order traversal
vector<int> getTopView(TreeNode<int> *root) {
    if(root == NULL) {
        return {};
    }
    map<int,int>mp;
    
    queue<pair<TreeNode<int>*, int> > q;
    q.push({root, 0});

    while(!q.empty()) {
        auto frnt = q.front().first;
        int level = q.front().second;
        int tp = frnt->val;
        if(mp.find(level) == mp.end()) {
            mp[level] = tp;
        }

        if(frnt->left) {
            q.push({frnt->left, level-1});
        }

        if(frnt->right) {
            q.push({frnt->right, level+1});
        }

        q.pop();
    }


    vector<int>res;
    for(auto it: mp) {
        res.push_back(it.second);
    }
    return res;
}
