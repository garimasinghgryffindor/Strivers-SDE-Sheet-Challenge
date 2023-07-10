Trapping Rainwater

Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.


Solution 1: Brute Force

// brute force
long long getTrappedWater(long long* height, int n) {
    long long sum=0;
        
    if(n==1)
        return 0;
    
    for(int i=1 ; i<n ; i++){
        long long leftMax = 0, rightMax = 0;
        int j = i;
        while(j >= 0) {
            leftMax = max(leftMax , height[j]);
            j--;
        }
        j = i;
        while(j < n) {
            rightMax = max(rightMax, height[j]);
            j++;
        }

        sum += min(leftMax, rightMax) - height[i];
    } 
    
    return sum;
}


Solution 2: Better Approach
        // using extra space
Approach: For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.



int trap(vector<int>& height) {
        int n=height.size() , sum=0;
        
        if(n==1)
            return 0;
        
        int left[n] , right[n];
        left[0] = height[0] , right[n-1] = height[n-1];
        for(int i=1 ; i<n ; i++){
            left[i] = max(left[i-1] , height[i]);
        } 
        for(int i=n-2 ; i>=0 ; i--){
            right[i] = max(height[i] , right[i+1]);
        }
        
        for(int i=0 ; i<n ; i++){
            int x = min(left[i] , right[i]);
            sum += x-height[i];
        }
        
        return sum;
    }





Solution 3: Better solution
Intuition: We are taking O(N) for computing leftMax and rightMax at each index. The complexity can be boiled down to O(1) if we precompute the leftMax and rightMax at each index.
Approach: Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand. Then use the formula min(prefix[I], suffix[i])-arr[i] to compute water trapped at each index.

int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0, rightmax = 0;
        int res = 0;
        int l=0, r=n-1;
        
        while(l<=r) {
            if(height[l] <= height[r]) {
                if(height[l] > leftmax) {
                    leftmax = height[l];
                } else {
                    res += leftmax - height[l];
                }
                l++;
            } else {
                if(height[r] > rightmax) {
                    rightmax = height[r];
                } else {
                    res += rightmax - height[r];
                }
                r--;
            }
        }
        
        return res;
    }
