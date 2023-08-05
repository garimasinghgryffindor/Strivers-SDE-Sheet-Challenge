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



// using MEMOIZATION
int recur(vector<int> &values,vector<int> &weights, int n, int W, int idx,vector<vector<int>>&dp) {
	if(idx >= n) return 0;

	if(dp[idx][W] != -1) return dp[idx][W];

	int ifTaken = 0, ifNotTaken = 0;
	if(W >= weights[idx]) {
		ifTaken = values[idx] + recur(values,weights,n,W-weights[idx],idx+1,dp);
	}

	ifNotTaken = 0 + recur(values,weights,n,W,idx+1,dp);

	return (dp[idx][W] = max(ifTaken, ifNotTaken));
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>>dp(n, vector<int>(w+1,-1));
	return recur(values,weights,n,w,0,dp);
}

