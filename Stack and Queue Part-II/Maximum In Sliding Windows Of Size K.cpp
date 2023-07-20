#include <bits/stdc++.h> 
// BRUTE FORCE
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int>res;
    int n = nums.size();
    int windows = n-k+1;
    // for the first window
    int idx = 0;
    for(int i=1 ; i<k ; i++) {
        if(nums[i] > nums[idx]) {
            idx = i;
        }
    }
    res.push_back(nums[idx]);

    for(int i=1 ; i<windows ; i++) {
        if(idx >= i) {
            // previous max still exists in the window
            // we just need to compare it with the new element
            if(nums[i+k-1] >= nums[idx]) {
                idx = i+k-1;
            }
        } else {
            //we have to calculate the new max
            idx = i;
            for(int j=i+1 ; j<=i+k-1 ; j++) {
                if(nums[j] >= nums[idx]) {
                    idx = j;
                }
            }
        }
        res.push_back(nums[idx]);
    }

    return res;
}
