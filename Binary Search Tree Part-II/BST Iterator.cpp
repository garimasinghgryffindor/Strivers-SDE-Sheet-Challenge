class BSTiterator
{
    public: 
    stack<int> st;
    void inorder(TreeNode<int>* root)
    {
        if(root==NULL)
        return;

        inorder(root->right);
        st.push(root->data);
        inorder(root->left);
        return;
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        inorder(root);
    }

    int next()
    {
        // write your code here
        if(st.empty())
        return -1;
        else
        {
            int z=st.top();
            st.pop();
            return z;
        } 

    }

    bool hasNext()
    {
        // write your code here
        if(st.empty())
        return false;
        else
        return true;
    }
};
