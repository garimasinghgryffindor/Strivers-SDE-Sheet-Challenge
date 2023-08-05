// using RECURSION
int lis(int arr[], int idx, int prevIdx, int n) {
    if(idx >= n) return 0;

    int notTake = 0 + lis(arr, idx+1, prevIdx, n);

    int take = 0;
    if(prevIdx == -1 || arr[idx] > arr[prevIdx]) {
        take = 1 + lis(arr, idx+1 , idx, n);
    }
    return max(take, notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    return lis(arr, 0, -1, n);
}


// using MEMOIZATION
vector<vector<int>>dp;
int lis(vector<int>&arr, int idx, int prevIdx) {
    if(idx >= arr.size()) return 0;

    if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];

    int notTake = 0 + lis(arr, idx+1, prevIdx);

    int take = 0;
    if(prevIdx == -1 || arr[idx] > arr[prevIdx]) {
        take = 1 + lis(arr, idx+1 , idx);
    }
    return dp[idx][prevIdx+1] = max(take, notTake);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    dp.resize(n, vector<int>(1+n, -1));
    
    return lis(nums, 0, -1);
}

