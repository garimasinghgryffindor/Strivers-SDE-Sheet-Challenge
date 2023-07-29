// let us try this thing

void leftTraversal(TreeNode<int>*root, vector<int>&vec,unordered_map<TreeNode<int>*,bool>&mp) {
    if(!root) return;
    
    if(root->left || root->right) {
        vec.push_back(root->data);
        mp[root] = true;
    }

    if(root->left)
        leftTraversal(root->left, vec, mp);
    else 
        leftTraversal(root->right, vec, mp);
}

void rightTraversal(TreeNode<int>*root,vector<int>&vec,unordered_map<TreeNode<int>*,bool>&mp) {
    if(!root) return;
    if(!mp[root] && (root->left || root->right)) {
        vec.push_back(root->data);
        mp[root] = true;
    }
    
    if(root->right)
        rightTraversal(root->right, vec, mp);
    else
        rightTraversal(root->left, vec, mp);
}

void leafTraversal(TreeNode<int>*root, vector<int>&vec, unordered_map<TreeNode<int>*,bool>&mp) {
    if(!root) return;
    if(!root->left && !root->right && !mp[root]) {
        vec.push_back(root->data);
        mp[root] = true;
    }

    leafTraversal(root->left, vec,mp);
    leafTraversal(root->right,vec,mp);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // left edge traversal
    // leaf nodes traversal
    // right edge traversal

    unordered_map<TreeNode<int>*, bool> mp;

    if(!root) return {};
    if(!root->left && !root->right) return {root->data};

    vector<int>left,leaf,right;

    leftTraversal(root,left,mp);
    leafTraversal(root,leaf,mp);
    rightTraversal(root,right,mp);

    reverse(right.begin(), right.end());

    vector<int>res;
    copy(left.begin(), left.end(), back_inserter(res));
    copy(leaf.begin(), leaf.end(), back_inserter(res));
    copy(right.begin(), right.end(), back_inserter(res));
    return res;
}


