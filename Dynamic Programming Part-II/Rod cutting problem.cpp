
// USING RECURSION
int recur(vector<int>&prices, int n, int idx, int prevCut) {
	if(idx > n) return 0;

	// either we will make cut at the current position
	int cutLength = idx-prevCut;
	int cutValue = prices[cutLength-1] + recur(prices, n, idx+1, idx);

	// or not
	int cutValue2 = recur(prices, n, idx+1, prevCut);

	return max(cutValue, cutValue2);
}
int cutRod(vector<int> &price, int n)
{
	return recur(price, n, 1, 0);
}


// USING MEMOIZATION
int recur(vector<int>&prices,int n,int idx,int prevCut,vector<vector<int>>&dp) {
	if(idx > n) return 0;

	if(dp[idx][prevCut] != -1) return dp[idx][prevCut];

	// either we will make cut at the current position
	int cutLength = idx-prevCut;
	int cutValue = prices[cutLength-1] + recur(prices, n, idx+1, idx, dp);

	// or not
	int cutValue2 = recur(prices, n, idx+1, prevCut, dp);

	return dp[idx][prevCut] = max(cutValue, cutValue2);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n+1, vector<int>(n,-1));
	return recur(price, n, 1, 0, dp);
}


// USING TABULATION
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n+2, vector<int>(n+1,0));

	for(int idx = n; idx >= 0; idx--) {
		for(int prevCut = idx-1; prevCut >=0; prevCut--) {
			int cutLength = idx-prevCut;
			int cutValue = price[cutLength-1] + dp[idx+1][idx];

			// or not
			int cutValue2 = dp[idx+1][prevCut];
			dp[idx][prevCut] = max(cutValue, cutValue2);
		}
	}

	return dp[1][0];
}

