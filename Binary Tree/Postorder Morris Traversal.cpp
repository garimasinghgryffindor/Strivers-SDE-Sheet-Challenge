// LEFT  ->  RIGHT  ->  NODE
// NOT using RECURSION
// using MORRIS TRAVERSAL
// Threaded Binary Tree

// similar to morris traversal for preorder -> NLR
// at last we will be reversing the vector

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>res;
    TreeNode * node = root;

    while(node != NULL) {
        if(node->right == NULL) {
            res.push_back(node->data);
            node = node->left;
        } else {
            // 2 cases
            // we have either reached the node for the very first time
            // or we are traversing it again after coming from the thread that we drew
            TreeNode * curr = node->right;
            // LEFTMOST ELEMENT OF THE RIGHT SUBTREE
            while(curr->left != NULL && curr->left != node) {
                curr = curr->left;
            }

            if(curr->left == NULL) {
                // first time visit
                res.push_back(node->data);
                curr->left = node;
                node = node->right;
            } else {
                curr->left = NULL;
                node = node->left;
            }
        }
    }

    reverse(res.begin(), res.end());

    return res;
}
