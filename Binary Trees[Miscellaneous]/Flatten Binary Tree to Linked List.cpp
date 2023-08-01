// APPROACH 1
// USING QUEUE TO STORE THE INORDER
void inorder(BinaryTreeNode<int>*root, queue<int>&q) {
    if(!root) return;
    inorder(root->left, q);
    q.push(root->data);
    inorder(root->right, q);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    queue<int>q;
    inorder(root,q);
    BinaryTreeNode<int> * dummy = new BinaryTreeNode<int>(0);
    BinaryTreeNode<int> * curr = dummy;
    while(!q.empty()) {
        curr->right = new BinaryTreeNode<int>(q.front());
        q.pop();
        curr->left = NULL;
        curr = curr->right;
    }

    return dummy->right;
}


// APPROACH 2
// DOES NOT REQUIRE 2 TRAVERSALS
// 1 TRAVERSAL
void recur(BinaryTreeNode<int>* root, BinaryTreeNode<int>*&head) {
    if(!root) return;

    recur(root->right, head);
    root->right = head;
    if(head) head->left = root;
    head = root;

    recur(root->left, head); 
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>*head = NULL;
    recur(root,head);
    return head;
}
