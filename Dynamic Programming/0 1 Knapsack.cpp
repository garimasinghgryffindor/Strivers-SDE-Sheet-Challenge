// using RECURSION
int recur(vector<int> &values,vector<int> &weights, int n, int W, int idx) {
	if(idx >= n) return 0;

	int ifTaken = 0, ifNotTaken = 0;
	if(W >= weights[idx]) {
		ifTaken = values[idx] + recur(values,weights,n,W-weights[idx],idx+1);
	}

	ifNotTaken = 0 + recur(values,weights,n,W,idx+1);

	return max(ifTaken, ifNotTaken);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return recur(values,weights,n,w,0);
}
