// using level order traversal
vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int>* , int> > q;
    q.push({root, 0});

    while(!q.empty()) {
        BinaryTreeNode<int> * frnt = q.front().first;
        int tp = frnt->data;
        int level = q.front().second;
        mp[level] = tp;
        if(frnt->left) {
            q.push({frnt->left, level-1});
        }
        if(frnt->right) {
            q.push({frnt->right, level+1});
        }
        q.pop();
    }

    vector<int>res;
    for(auto x: mp) {
        res.push_back(x.second);
    }

    return res;
}
