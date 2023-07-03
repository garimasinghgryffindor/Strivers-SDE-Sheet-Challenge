Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array

Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.


Solution 1: Brute-Force
Approach: Simply count the no. of appearance for each element using nested loops and whenever you find the count of an element greater than N/3 times, that element will be your answer.

vector < int > majorityElement(int arr[], int n) {
  vector < int > ans;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] == arr[i])
        cnt++;
    }

    if (cnt > (n / 3)) 
      ans.push_back(arr[i]);
  }

  return ans;
}



Solution 2: Better Solution
Approach: Traverse the whole array and store the count of every element in a map. After that traverse through the map and whenever you find the count of an element greater than N/3 times, store that element in your answer.

vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        unordered_map<int , int> mp;
        
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        int cmp = nums.size()/3;
        
        for(auto it : mp){
            if(it.second > cmp)
                res.push_back(it.first);
        }
        
        return res;
    }



Solution 3: Optimal Solution (Extended Boyer Moore’s Voting Algorithm)
Approach + Intuition: In our code, we start by declaring a few variables:
num1 and num2 will store our current most frequent and second most frequent elements.
c1 and c2 will store their frequency relative to other numbers.
We are sure that there will be a max of 2 elements that occurs > N/3 times because there cannot be if you do a simple math addition.
Let, ele be the element present in the array at any index. 
if ele == num1, so we increment c1.
if ele == num2, so we increment c2.
if c1 is 0, so we assign num1 = ele.
if c2 is 0, so we assign num2 = ele.
In all the other cases we decrease both c1 and c2.
In the last step, we will run a loop to check if num1 or nums2 are the majority elements or not by running a for loop check.  Intuition: Since it’s guaranteed that a number can be a majority element, hence it will always be present at the last block, hence, in turn, will be on nums1 and nums2. For a more detailed explanation, please watch the video below.


vector<int> majorityElement(vector<int>& nums) {
        // using (Extended Boyer Moore’s Voting Algorithm)
        int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0;
        int n = nums.size();
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == num1) {
                count1++;
            } else if(nums[i] == num2) {
                count2++;
            } else if(count1 == 0) {
                num1 = nums[i];
                count1 = 1;
            } else if(count2 == 0) {
                num2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        count1=0, count2=0;
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == num1) {
                count1++;
            } else if(nums[i] == num2) {
                count2++;
            }
        }
        
        vector<int> res;
        if(count1>n/3) {
            res.push_back(num1);
        }
        if(count2>n/3) {
            res.push_back(num2);
        }
        
        return res;
    }
