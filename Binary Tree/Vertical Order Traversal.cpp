vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if(!root) return {};

    map<int , map<int, vector<int> > > nodes;
    queue<pair<TreeNode<int>*, pair<int,int> > >q;
    q.push({root,{0,0}});

    while(!q.empty()) {
        auto tp = q.front();
        q.pop();
        TreeNode<int> * node = tp.first;
        int x = tp.second.first;
        int y = tp.second.second;
        nodes[x][y].push_back(node->data);

        if(node->left) {
            q.push({node->left, {x-1,y+1}});
        }

        if(node->right) {
            q.push({node->right, {x+1,y+1}});
        }
    }

    vector<int>res;
    for(auto x: nodes) {
        for(auto y: x.second) {
            for(int z: y.second) {
                res.push_back(z);
            }
        }
    }
    return res;
}

