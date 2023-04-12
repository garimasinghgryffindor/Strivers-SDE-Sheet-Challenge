3 Sum : Find triplets that add up to a zero

Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

Solution 1 (Brute Force):
Intuition: While starting out, our aim must be to come up with a working solution first. Thus, given the problem, the most intuitive solution would be using three-pointers and checking for each possible triplet, whether we can satisfy the condition or not.
Approach: We keep three-pointers i,j, and k. For every triplet we find the sum of A[i]+A[j]+A[k]. If this sum is equal to zero, we’ve found one of the triplets. We add it to our data structure and continue with the rest.

vector < vector < int >> threeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}




Solution 2 (Optimized Approach):
Intuition: Can we do something better?
I think yes! In our intuitive approach, we were considering all possible triplets. But do we really need to do that? I say we fixed two pointers i and j and came out with a combination of [-1,1,1] which doesn’t satisfy our condition. However, we still check for the next combination of say [-1,1,2] which is worthless. (Assuming the k pointer was pointing to 2).
Approach:
We could make use of the fact that we just need to return the triplets and thus could possibly sort the array. This would help us use a modified two-pointer approach to this problem.
Eg) Input :  [-1,0,1,2,-1,-4]
After sorting, our array is : [-4,-1,-1,0,1,2]
Notice, that we are fixing the i pointer and then applying the traditional 2 pointer approach to check whether the sum of three numbers equals zero. If the sum is less than zero, it indicates our sum is probably too less and we need to increment our j pointer to get a larger sum. On the other hand, if our sum is more than zero, it indicates our sum is probably too large and we need to decrement the k pointer to reduce the sum and bring it closer to zero.



vector<vector<int>> threeSum(vector<int>& nums) {
        
        const size_t len = nums.size();
        if (len < 3)
            return {};
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> unique_results;
        
        for(int i = 0; i < len - 2; i++) {
            
            int j = i + 1;
            int k = len - 1;
            
            while (j < k) {
            
                const int sum = nums[i] + nums[j] + nums[k];
                if (0 == sum) {
                    unique_results.insert((vector<int>){nums[i], nums[j++], nums[k--]});
                }
                else if (0 > sum)
                    j++;
                else if (0 < sum)
                    k--;
            }
        }
        
        vector <vector <int> > res;
        
        copy(unique_results.begin(), unique_results.end(),back_inserter(res));
        return res;
    }
