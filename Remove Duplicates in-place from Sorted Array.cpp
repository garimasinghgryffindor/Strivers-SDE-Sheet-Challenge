Remove Duplicates in-place from Sorted Array

Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.
If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.


Solution 1: Brute Force
Intuition: We have to think of a data structure that does not store duplicate elements. So can we use a Hash set? Yes! We can. As we know HashSet only stores unique elements.




int removeDuplicates(vector<int>& nums) {
        set<int> ans;
        for(int x: nums) {
            ans.insert(x);
        }
        int i=0;
        for(auto x: ans) {
            nums[i++] = x;
        }
        
        return ans.size();
    }




Solution 2: Two pointers
Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j]. 
Approach:
Take a variable i as 0;
Use a for loop by using a variable ‘j’ from 1 to length of the array.
If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
 After completion of the loop return i+1, i.e size of the array of unique elements.


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0 , j=i+1;
        int n = nums.size();
        
        while(j<n) {
            if(nums[i] != nums[j]) {
                // A ok
                i++;
                nums[i] = nums[j];
            } else {
                j++;
            }
        }
        
        return i+1;
    }
};
