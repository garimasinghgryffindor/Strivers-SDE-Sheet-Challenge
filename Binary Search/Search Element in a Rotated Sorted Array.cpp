Search Element in a Rotated Sorted Array

Problem Statement: 
There is an integer array nums sorted in ascending order (with distinct values). Given the array nums after the possible clockwise rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums. We need to search a given element in a rotated sorted array.


Solution 1: Using Linear Search
Approach :
We will iterate through the array completely. While iterating, we have to check if we have found the target element in the array. If we find it, we will return its index. If we iterate completely and still do not find an element in the array. This indicates the target is not present and hence we return -1 as mentioned in the question.


int search(vector<int>& nums,int target) {
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==target)
            return i;
    }
    return -1;
     
}



Solution 2: Using Binary Search
Intuition :
It is mentioned that the array given is sorted but in a rotated manner. So, we can divide a given array into two parts that are sorted. This gives us hints to use binary search. We can visualize a given array to be composed of two sorted arrays.


int search(vector<int>& nums, int target) {
        int low = 0, high=nums.size()-1;
        while(low <=high)
        {
            int  mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[low])
            {
	    //left half sorted;

                //this part is sorted part;
                if(target>=nums[low]&&target<nums[mid])
                 high=mid-1;
                else
                    low=mid+1;
                
            }
            else {
	    // right half sorted                

                // this part is sorted
                if(target<=nums[high]&&target>nums[mid])
                    low =mid+1;
                else
                    high=mid-1;
                
            }
        }
        return -1;
    }

