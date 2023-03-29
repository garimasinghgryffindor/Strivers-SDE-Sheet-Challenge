Find the duplicate in an array of N+1 integers

Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

Solution 1:Using sorting

Approach: Sort the array. After that, if there is any duplicate number they will be adjacent.So we simply have to check if arr[i]==arr[i+1] and if it is true,arr[i] is the duplicate number.


int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}




Solution 2: Using frequency array
Approach: Take a frequency array of size N+1 and initialize it to 0. Now traverse through the array and if the frequency of the element is 0 increase it by 1, else if the frequency is not 0 then that element is the required answer.

int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  int freq[n + 1] = {
    0
  };
  for (int i = 0; i < n; i++) {
    if (freq[arr[i]] == 0) {
      freq[arr[i]] += 1;
    } else {
      return arr[i];
    }
  }
  return 0;
}




Solution 3: Using binary search

class Solution {
public:
    int binarySearch(vector<int>nums,int l , int r){
        if(nums[l] == nums[l+1])
            return nums[l];
        if(nums[r] == nums[r-1])
            return nums[r];
        
        int mid = l + (r-l)/2;
        if(mid >= nums[mid]){
            if(nums[mid-1] == nums[mid])
                return nums[mid];
            
            return binarySearch(nums,l,mid-1);
        }
        
        return binarySearch(nums,mid+1 , r);
    }
    
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int res = binarySearch(nums, 0 , n-1);
        
        return res;
    }
};



Solution 3: Linked List cycle method

// two-pointer approach
// Linked List cycle method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);
        
        fast = nums[0];
        while(slow!=fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
