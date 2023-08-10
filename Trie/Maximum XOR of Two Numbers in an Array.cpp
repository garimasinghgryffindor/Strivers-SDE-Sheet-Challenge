// using BRUTE FORCE
int findMaximumXOR(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int temp = nums[i] ^ nums[j];
            res = max(res, temp);
        }
    }
    return res;
}


