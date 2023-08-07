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



// using TABULATION
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n, 0);
    dp[0] = 1;
    for(int i = 1 ; i < n ; i++) {
        dp[i] = 1;
        for(int j = 0 ; j < i ; j++) {
            if(nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}


class Solution {
public:
    // using TABULATION
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1,0));

        for(int i=n-1 ; i>=0 ; i--) {
            for(int j = i-1 ; j >= -1 ; j--) {
                int notTake = 0 + dp[i+1][j+1];
                int take = 0;
                if(j == -1 || arr[i] > arr[j]) {
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};






