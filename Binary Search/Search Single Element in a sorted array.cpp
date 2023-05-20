Search Single Element in a sorted array

Problem Statement: Given a sorted array of N integers, where every element except one appears exactly twice and one element appears only once. Search Single Element in a sorted array.


Solution 1: Using XOR(^)
Approach: As every number in the array repeats twice and only one number occurs once, we can take advantage of the XOR(^) operator. These are two properties of the XOR operator which will be helpful.
If p is a number then,
p^p=0
p^0=p
If we find the XOR of every element of the array, we will get the answer.


int findSingleElement(vector < int > & nums) {
            
            int n = nums.size();
            int elem = 0;
            for (int i = 0; i < n; i++) {
                elem = elem ^ nums[i];
            }
            
            return elem;
        }



Solution 2:
Approach: Using Binary Search
As the elements are sorted, twice-occurring elements will be placed together in the input array. Moreover, the input array has one element occurring once, therefore a general input can be thought of like this.








class Solution {
public:
    int binarySearch(vector<int>&nums, int l , int r) {
        if(l <= r) {
            int mid = l + (r-l)/2;
            // there could be two extreme cases
            if(mid == 0) {
                if(nums[mid]!=nums[mid+1])
                    return nums[mid];
                return -1;
            }
            
            if(mid == nums.size()-1) {
                if(nums[mid]!=nums[mid-1])
                    return nums[mid];
                return -1;
            }
            
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            
            // second question -> where to go if the element is not found
            // see normally all the elements will be like->
            //      1  1  2  2  3  3
            //indx  0  1  2  3  4  5
            // even idx and then odd index
            
            if(nums[mid] == nums[mid-1] && mid%2==1) {
                return binarySearch(nums, mid+1, r);
            }
            
            if(nums[mid] == nums[mid-1] && mid%2==0) {
                return binarySearch(nums, l, mid-2);
            }
            
            if(nums[mid] == nums[mid+1] && mid%2==0) {
                return binarySearch(nums, mid+2 , r);
            }
            
            if(nums[mid] == nums[mid+1] && mid%2==1) {
                return binarySearch(nums, l, mid-1);
            }
        }
        
        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        return binarySearch(nums, 0, nums.size()-1);
    }
};
