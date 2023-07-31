pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* curr = root;
    int pre = -1, succ = -1;
    // find the node
    while(curr->data != key) {
        if(curr->data > key) {
            succ = curr->data;
            curr = curr->left;
        }
        else {
            pre = curr->data;
            curr = curr->right;
        }
    }

    BinaryTreeNode<int>*leftSubtree = curr->left;
    while(leftSubtree) {
        pre = leftSubtree->data;
        leftSubtree = leftSubtree->right;
    }

    BinaryTreeNode<int>*rightSubtree = curr->right;
    while(rightSubtree) {
        succ = rightSubtree->data;
        rightSubtree = rightSubtree->left;
    }

    return {pre , succ};
}
