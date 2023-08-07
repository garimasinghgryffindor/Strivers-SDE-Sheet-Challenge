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

