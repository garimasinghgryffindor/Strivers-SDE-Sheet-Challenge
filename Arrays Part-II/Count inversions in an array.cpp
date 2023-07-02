Count inversions in an array

Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].


Solution 1: Brute - force

Solution 2: (merge sort)

// using Modified Merge Sort

class Solution {
public:
    int merge(vector<int>&nums,int left,int mid,int right) {
        vector<int> temp(nums.size());
        
        int invCount = 0;
        int i=left, j=mid+1,k = left;
        
        while(i<=mid && j<=right) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
                invCount += mid - i + 1;
            }
        }
        
        while(i <= mid) {
            temp[k++] = nums[i++];
        }
        while(j <= right) {
            temp[k++] = nums[j++];
        }
        
        for(int i=0 ; i<nums.size() ; i++) {
            nums[i] = temp[i];
        }
        
        return invCount;
    }
    
    int mergeSort(vector<int>&nums,int left,int right) {
        int inversionCount = 0;
        if(left < right) {
            int mid = left + (right-left)/2;
            
            inversionCount += mergeSort(nums,left,mid);
            inversionCount += mergeSort(nums,mid+1,right);
            inversionCount += merge(nums, left, mid, right);
        }
        return inversionCount;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        
        return mergeSort(nums,0,n-1);
    }
};
