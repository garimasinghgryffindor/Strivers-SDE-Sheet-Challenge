
// NODE  -> LEFT ->  RIGHT
// NOT using RECUSION
// MORRIS TRAVERSAL
// using Threaded Binary Tree
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>res;
    TreeNode * node = root;

    while(node != NULL) {
        // if the left is null 
        if(node->left == NULL) {
            res.push_back(node->data);
            node = node->right;
        } else {
            // that is node's left is not equal to NULL
            // means I need to visit the left node first and then the current node
            // but how would I backtrack to the current node again -> since there is
            // no pointer back to the parent
            // I will be creating a thread back to the parent
            // Only after the entire left substree will be completely visited,
            // then only I will be returning back to the parent
            // and since the traversal is like LEFT -> NODE -> RIGHT
            // means last traversal is RIGHT one
            // therefore, we will be connnecting the Rightmost element of the leftsubtree
            // back to the parent, before actually traversing the left subtree

            // GO TO THE RIGHTMOST ELEMENT OF THE LEFT SUBSTREE
            TreeNode *curr = node->left;
            while(curr->right != NULL && curr->right != node) {
                curr = curr->right;
            }

            if(curr->right == NULL) {
                // thread has not been created yet
                // create the thread
                res.push_back(node->data);
                curr->right = node;
                // and then move to the left subtree
                node = node->left;
            } else {
                // thread has already been created
                // remove the thread
                curr->right = NULL;
                // and go to the right subtree
                node = node->right;
            }
        }
    }

    return res;
}
