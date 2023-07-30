int search(vector<int>vec,int key,int l,int r) {
     for(int i=l ; i<=r ; i++) {
          if(vec[i] == key)
               return i;
     }
}

TreeNode<int>* recur(vector<int>inorder,vector<int>postorder,int&index,int l,int r) {
     if(l > r || index >= inorder.size()) return NULL;
     int val = postorder[index++];
     TreeNode<int>*node = new TreeNode<int>(val);

     int idx = search(inorder,val,l,r);
     
     node->right = recur(inorder, postorder, index, idx+1,r);
     node->left = recur(inorder, postorder, index, l, idx-1);
     return node;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	reverse(postOrder.begin(), postOrder.end());
     int index = 0;
     int n = inOrder.size();
     return recur(inOrder,postOrder,index,0,n-1);
}
