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
