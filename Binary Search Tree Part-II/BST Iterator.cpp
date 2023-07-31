// APPROACH 1
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


// APPROACH 2
class BSTiterator
{
    public: 
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        pushall(root);
    }

    int next()
    {
        auto ptr = st.top();
        st.pop();
        pushall(ptr->right);
        return ptr->data;
    }

    bool hasNext()
    {
        return (!st.empty());
    }

    void pushall(TreeNode<int>* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
};

