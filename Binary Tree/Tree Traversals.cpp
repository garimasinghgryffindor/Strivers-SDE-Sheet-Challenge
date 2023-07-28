// INORDER PREORDER AND POSTORDER IN ONE TRAVERSAL
// using Stack
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(!root) return {{}};

    vector<int>preorder, inorder, postorder;
    stack<pair<BinaryTreeNode<int>*, int> > st;
    st.push({root, 1});

    while(!st.empty()) {
        auto tp = st.top();
        st.pop();

        if(tp.second == 1) {
            preorder.push_back((tp.first)->data);
            st.push({tp.first, 2});
            
            if((tp.first)->left) {
                st.push({(tp.first)->left, 1});
            }
        }
        else if(tp.second == 2) {
            inorder.push_back((tp.first)->data);
            st.push({tp.first, 3});

            if((tp.first)->right) {
                st.push({(tp.first)->right, 1});
            }
        }
        else {
            postorder.push_back((tp.first)->data);
        }
    }

    vector<vector<int>> res;
    res.push_back(inorder);
    res.push_back(preorder);
    res.push_back(postorder);

    return res;
}
