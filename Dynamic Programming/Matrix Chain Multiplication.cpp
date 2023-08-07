// USING RECURSION
int recur(vector<int>&arr, int i, int j) {
    if(i == j) return 0;
    int res = INT_MAX;
    for(int k = i ; k < j ; k++) {
        int operations = arr[i-1]*arr[k]*arr[j];
        int total_operations = operations + recur(arr,i,k) + recur(arr,k+1,j);
        res = min(res, total_operations);
    }

    return res;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return recur(arr,1,N-1);
}
