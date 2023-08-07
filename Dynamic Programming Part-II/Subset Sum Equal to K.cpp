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
