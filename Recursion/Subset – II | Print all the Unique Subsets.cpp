Subset – II | Print all the Unique Subsets

Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

Solution 1: Brute Force
Approach: At every index, we make a decision whether to pick or not pick the element at that index. This will help us in generating all possible combinations but does not take care of the duplicates. Hence we will use a set to store all the combinations that will discard the duplicates.


    void recur(vector<int>nums,set<vector<int>>&res,vector<int>temp,int i) {
        if(i==nums.size()) {
            res.insert(temp);
            return;
        }
        recur(nums,res,temp,i+1);
        temp.push_back(nums[i]);
        recur(nums,res,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>res2;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        recur(nums,res2,temp,0);
        
        vector<vector<int>> res(res2.begin(),res2.end());
        
        return res;
        
    }
};


Solution 2: Optimal
Approach: 
In the previous method, we were taking extra time to store the unique combination with the help of a set.  To make the solution efficient we will have to decide on a method that will consider only the unique combinations without the help of additional data structure.

Lets  understand  with an example where arr = [1,2,2 ].

Initially start with an empty data structure. In the first recursion, call make a subset of size one, in the next recursion call a subset of size 2, and so on. But first, in order to make a subset of size one what options do we have?

We can pick up elements from either the first index or the second index or the third index. However, if we have already picked up two from the second index, picking up two from the third index will make another duplicate subset of size one. Since we are trying to avoid duplicate subsets we can avoid picking up from the third index. This should give us an intuition that whenever there are duplicate elements in the array we pick up only the first occurrence.

The next recursion calls will continue from the point the previous one ended.
Let’s summarize:-

Sort the input array.Make a recursive function that takes the input array ,the current subset,the current index and  a list of list/ vector of vectors to contain the answer.

Try to make a subset of size n during the nth recursion call and consider elements from every index while generating the combinations. Only pick up elements that are appearing for the first time during a recursion call to avoid duplicates.

Once an element is picked up, move to the next index.The recursion will terminate when the end of array is reached.While returning backtrack by removing the last element that was inserted.


class Solution {
public:
    void recur(vector<int>nums,vector<vector<int>>&res,vector<int>temp,int i) {
        res.push_back(temp);
        
        for(int j=i ; j<nums.size() ; j++) {
            if(j!=i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            recur(nums,res,temp,j+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        recur(nums,res,temp,0);
        
        return res;
        
    }
};
