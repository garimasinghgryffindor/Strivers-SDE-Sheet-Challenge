Count Reverse Pairs

Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[I]>2*arr[j].

Solution 1: Brute Force Approach
Intuition : 
As we can see from the given question that i < j, So we can just use 2 nested loops and check for the given condition which is arr [i] > 2* arr[j].
Approach:
We will be having 2 nested For loops the outer loop having i as pointer 
The inner loop with j as pointer and we will make sure that 0 <= i < j < arr.length() and also arr[i] > 2*arr[j] condition must be satisfied.

 int reversePairs(vector < int > & arr) {
      int Pairs = 0;
      for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
          if (arr[i] > 2 * arr[j]) Pairs++;
        }
      }
      return Pairs;
    }



Solution 2: Optimal Solution
Intuition:
-> We will be using the Merge Sort Algorithm to solve this problem. We split the whole array into 2  parts creating a Merge Sort Tree-like structure. During the conquer step we do the following task : 
-> We take the left half of the Array and Right half of the Array, both are sorted in themselves. 
-> We will be checking the following condition arr[i] <= 2*arr[j]  where i is the pointer in the Left Array and j is the pointer in the Right Array. 
-> If at any point arr[i] <= 2*arr[j] , we add 1  to the answer as this pair has a contribution to the answer. 
-> If Left Array gets exhausted before Right Array we keep on adding the distance j pointer traveled as both the arrays are Sorted so the next ith element from Left Subarray will equally contribute to the answer.
-> The moment when both Arrays get exhausted we perform a merge operation. This goes on until we get the original array as a Sorted array.


Approach :  
-> We, first of all, call a Merge Sort function, in that we recursively call Left Recursion and Right Recursion after that we call the Merge function in order to merge both Left and Right Calls we initially made and compute the final answer.
-> In the Merge function, we will be using low, mid, and high values to count the total number of inversion pairs for the Left half and Right half of the Array.
->  Now, after the above task, we need to Merge the both Left and Right sub-arrays using a temporary vector.
-> After this, we need to copy back the temporary vector to the Original Array. Then finally we return the number of pairs we counted.


int merge(vector<int>&nums,int l,int mid,int r) {
        int count = 0;
        int j = mid+1;
        
        for(int i=l ; i<=mid ; i++) {
            while(j<=r && nums[i] > 2LL*nums[j]) {
                j++;
            }
            count += j-(mid+1);
        }
        
        vector<int>temp;
        int left = l, right = mid+1;
        
        while(left <= mid && right <= r) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        
        while(left<=mid) {
            temp.push_back(nums[left++]);
        }
        
        while(right<=r) {
            temp.push_back(nums[right++]);
        }
        
        for(int i=l; i<=r ; i++) {
            nums[i] = temp[i-l];
        }
        
        return count;
    }
    
    int mergeSort(vector<int>&nums,int l,int r) {
        int revCount = 0;
        if(r > l) {
            int mid = l + (r-l)/2;
            revCount += mergeSort(nums,l,mid);
            revCount += mergeSort(nums,mid+1,r);
            revCount += merge(nums,l,mid,r);
        }
        return revCount;
    }
    
    int reversePairs(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        return mergeSort(nums, 0, nums.size()-1);
    }
