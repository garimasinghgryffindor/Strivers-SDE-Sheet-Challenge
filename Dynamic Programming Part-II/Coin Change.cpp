// USING RECURSION
int recur(int *denominations, int target, int idx) {
    if(target == 0) return 1;
    if(idx < 0) return 0;

    int notTake = recur(denominations, target, idx-1);
    int take = 0;
    if(target >= denominations[idx]) {
        take = recur(denominations, target-denominations[idx], idx);
    }
    return take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return recur(denominations, value, n-1);
}



// USING MEMOIZATION
long recur(int *denominations,int target,int idx,vector<vector<long>>&dp) {
    if(target == 0) return 1;
    if(idx < 0) return 0;

    if(dp[idx][target] != -1) return dp[idx][target];

    long notTake = recur(denominations, target, idx-1, dp);
    long take = 0;
    if(target >= denominations[idx]) {
        take = recur(denominations, target-denominations[idx], idx, dp);
    }
    return dp[idx][target] = take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n, vector<long>(value+1, -1));
    return recur(denominations, value, n-1, dp);
}



// USING TABULATION
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n+1, vector<long>(value+1, 0));

    for(int i=0 ; i<n ; i++) dp[i][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= value; j++) {
            long notTake = dp[i][j];
            long take = 0;
            if(j >= denominations[i]) {
                take = dp[i+1][j-denominations[i]];
            }
            dp[i+1][j] = take + notTake;
        }
    }

    return dp[n][value];
}
