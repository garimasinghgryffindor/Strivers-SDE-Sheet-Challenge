// using RECURSION
bool recur(vector<int>&arr, int sum, int idx) {
    if(sum == 0) return true;
    if(idx < 0) return false;

    bool take = 0;
    if(arr[idx] <= sum) {
        take = recur(arr, sum - arr[idx], idx-1);
    }
    bool notTake = recur(arr, sum, idx-1);

    return take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return recur(arr, k, n-1);
}


// using MEMOIZATION
bool recur(vector<int>&arr,int sum,int idx,vector<vector<int>>&dp) {
    if(sum == 0) return true;
    if(idx < 0) return false;

    if(dp[idx][sum] != -1) return dp[idx][sum];

    bool take = 0;
    if(arr[idx] <= sum) {
        take = recur(arr, sum - arr[idx], idx-1, dp);
    }
    bool notTake = recur(arr, sum, idx-1, dp);

    return dp[idx][sum] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    return recur(arr, k, n-1,dp);
}


// using TABULATION
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n+1, vector<bool>(k+1, false));

    for(int i = 0; i < n+1; i++) dp[i][0] = true;

    if(arr[0]<=k)
        dp[1][arr[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            bool take = false;
            if(arr[i] <= j) {
                take = dp[i][j - arr[i]];
            }
            bool notTake = dp[i][j];
            dp[i+1][j] = take || notTake;
        }
    }
    return dp[n][k];
}



