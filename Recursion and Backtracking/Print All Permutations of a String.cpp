Print All Permutations of a String/Array

Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.

Solution 1: Recursive
Approach: We have given the nums array, so we will declare an ans vector of vector that will store all the permutations also declare a data structure.
Declare a map and initialize it to zero and call the recursive function
Base condition:
When the data structure’s size is equal to n(size of nums array)  then it is a permutation and stores that permutation in our ans, then returns it.



private:
    void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }



Solution 2: With Backtracking.

Approach: Using backtracking to solve this.  We have given the nums array, so we will declare an ans vector of vector that will store all the permutations.
Call a recursive function that starts with zero, nums array, and ans vector.
Declare a map and initialize it to zero and call the recursive function.

Base condition:
Whenever the index reaches the end take the nums array and put it in ans vector and return.

Recursion:
Go from index to n – 1 and swap once the swap has been done call recursion for the next state. After coming back from the recursion make sure you re-swap it because, for the next element, the swap will not take place.


void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void permutation(vector<int>&nums , int l , int r , vector<vector<int> >&res)
    {
        if(l==r)
        {
            res.push_back(nums);
        }
        
        else
        {
            for(int i=l ; i<=r ; i++)
            {
                swap(nums[l] , nums[i]);
                
                permutation(nums, l+1 , r , res);
                
                swap(nums[i] , nums[l]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > res;
        int l = 0 , r = nums.size()-1;
        
        permutation(nums, l ,r ,res);
        
        return res;
    }
