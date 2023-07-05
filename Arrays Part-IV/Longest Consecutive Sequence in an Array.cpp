Longest Consecutive Sequence in an Array

Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.


Solution 1: (Brute force)
Approach: We can simply sort the array and run a for loop to find the longest consecutive sequence.

int longestConsecutive(vector<int> nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }


Solution 2: (Optimal Approach)
Approach: We will first push all elements in the HashSet. Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. Using this we can calculate the length of the longest consecutive subsequence. 

int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        
        set<int> st;
        for(auto x: nums) {
            st.insert(x);
        }
        
        int maxm = 0;
        
        for(auto x: nums) {
            if(!st.count(x-1)) {
                int currStreak = 1;
                int currNum = x;
                while(st.count(currNum+1)) {
                    currNum++;
                    currStreak++;
                }
                
                maxm = max(maxm, currStreak);
            }
        }
        
        return maxm;
    }
