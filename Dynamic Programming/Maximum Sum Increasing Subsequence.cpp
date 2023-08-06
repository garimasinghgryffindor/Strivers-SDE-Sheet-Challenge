
// RECURSION
int recur(vector<int>&rack, int idx, int prevWeight) {
	if(idx >= rack.size()) return 0;

	int take = 0, notTake = 0;
	if(rack[idx] > prevWeight) {
		take = rack[idx] + recur(rack, idx+1, rack[idx]);
	}

	notTake = 0 + recur(rack, idx+1, prevWeight);

	return max(take, notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	return recur(rack, 0, 0);
}


// MEMOIZATION
int recur(vector<int>&rack, int idx, int prevWeight,vector<vector<int>>&dp) {
	if(idx >= rack.size()) return 0;

	if(dp[idx][prevWeight+1] != -1) return dp[idx][prevWeight+1];

	int take = 0, notTake = 0;
	if(prevWeight == -1 || rack[idx] > rack[prevWeight]) {
		take = rack[idx] + recur(rack, idx+1, idx, dp);
	}

	notTake = 0 + recur(rack, idx+1, prevWeight, dp);

	return (dp[idx][prevWeight+1] = max(take, notTake));
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, -1));
	return recur(rack, 0, -1,dp);
}



// TABULATION
// just like LIS
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<int>msis(n);
	for( int i = 0 ; i < n ; i++ ) 
		msis[i] = rack[i]; 
	
	for ( int i = 1; i < n; i++ ) 
        for ( int j = 0; j < i; j++ ) 
            if (rack[i] > rack[j] && msis[i] < msis[j] + rack[i]) 
                msis[i] = msis[j] + rack[i]; 
	
	int ans = 0;
	for(int i=0 ; i<n ; i++) {
		ans = max(ans, msis[i]);
	}
	return ans;
}

