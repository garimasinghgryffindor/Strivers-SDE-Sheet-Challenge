// let us try this thing
bool isLeaf(TreeNode<int>* root){
    if(root->left==NULL and root->right==NULL){
        return true;
    }
    return false;
}

void addLeft(TreeNode<int>* root,vector<int>&res){

    TreeNode<int>*cur=root->left;

    while(cur!=NULL){
        if(!isLeaf(cur)){
            res.push_back(cur->data);
        }

        if(cur->left==NULL){
            cur=cur->right;
        }
        else{
            cur=cur->left;
        }
    }
}

void addRight(TreeNode<int>* root,vector<int>&res){

    TreeNode<int>*cur=root->right;

    stack<int>st;
    while (cur != NULL) {
        if (!isLeaf(cur)) {
            st.push(cur->data);
        }

        if (cur->right == NULL) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
}

void addLeaf(TreeNode<int>* root,vector<int>&res){

    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left!=NULL){
        addLeaf(root->left,res);
    }

    if(root->right!=NULL){
        addLeaf(root->right,res);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>res;
    if(root==NULL){
        return res;
    }
    if(!isLeaf(root)){
        res.push_back(root->data);
    }
    addLeft(root,res);
    addLeaf(root,res);
    addRight(root,res);
    return res;

}
