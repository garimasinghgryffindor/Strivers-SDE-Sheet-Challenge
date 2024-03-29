// APPROACH 1
// USING DFS
vector<int> dfs(TreeNode<int> *root, int x, vector<int>res) {
	if(!root) return {};
	res.push_back(root->data);
	if(root->data == x) return res;

	vector<int>res1 = dfs(root->left, x, res);
	if(res1.size()) return res1;

	vector<int>res2 = dfs(root->right,x, res);
	if(res2.size()) return res2;

	return {};
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // let us use dfs
	vector<int>res;
	res = dfs(root,x,{});
	return res;
}



// using DFS
bool dfs(TreeNode<int> *root, int x, vector<int>&res) {
	if(!root) return false;

	res.push_back(root->data);
	if(root->data == x) return true;

	if(dfs(root->left,x,res) || dfs(root->right,x,res)) {
		return true;
	}

	res.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // let us use dfs
	vector<int>res;
	dfs(root,x,res);
	return res;
}



