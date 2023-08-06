
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
