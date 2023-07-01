  Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
  has the largest sum and returns its sum and prints the subarray.



  1: Naive Approach 
  Approach: Using three for loops, we will get all possible subarrays in two loops and their sum in another loop, and then return the maximum of them.

  #include<bits/stdc++.h>

  using namespace std;
  int maxSubArray(vector < int > & nums, vector < int > & subarray) {
    int max_sum = INT_MIN;
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    int i, j;
    for (i = 0; i <= n - 1; i++) {
      for (j = i; j <= n - 1; j++) {
        int sum = 0;
        for (int k = i; k <= j; k++)
          sum = sum + nums[k];
        if (sum > max_sum) {
          subarray.clear();
          max_sum = sum;
          subarray.push_back(i);
          subarray.push_back(j);

        }
      }
    }
    return max_sum;
  }

  2: A better approach
  We can also do this problem using only two loops, we will avoid 3rd loop which was used in the above approach, instead of that we will create a new variable curr_sum, which stores the array sum from the ith index to the jth index.

  int maxSubArray(vector < int > & nums, vector < int > & subarray) {
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      int curr_sum = 0;
      for (int j = i; j < nums.size(); j++) {
        curr_sum += nums[j];
        if (curr_sum > max_sum) {
          subarray.clear();
          max_sum = curr_sum;
          subarray.push_back(i);
          subarray.push_back(j);
        }
      }
    }
    return max_sum;
  }



  3: Optimal Solution: Kadane’s Algorithm 


  class Solution {
  public:
      int maxSubArray(vector<int>& arr) {
          int sum = INT_MIN, tempSum=0;
          for(int i=0 ; i<arr.size() ; i++) {
              tempSum+=arr[i];
              if(tempSum>sum) {
                  sum = tempSum;
              }
              if(tempSum < 0) {
                  tempSum = 0;
              }
          }

          return sum;
      }
  };
