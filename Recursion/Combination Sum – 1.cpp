Combination Sum – 1

Problem Statement: 
Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


Solution: Recursion

Intuition:
For questions like printing combinations or subsequences, the first thing that should strike your mind is recursion.

How to think recursively?
Whenever the problem is related to picking up elements from an array to form a combination, start thinking about the “pick and non-pick” approach.



void combo(vector<int> &candidates , vector<vector<int> >&res , int target , int&sum , vector<int>&thisVector , int index){
        if(sum>target)
        {
            return;
        }
        if(sum==target)
        {  
            res.push_back(thisVector);
            return;
        }

        for(int i=index ; i<candidates.size() ; i++){
            thisVector.push_back(candidates[i]);
            sum+=candidates[i];
            combo(candidates , res , target , sum , thisVector,i);
            thisVector.pop_back();
            sum-=candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> thisVec;
        int sum=0 , index=0;
        combo(candidates , res , target, sum , thisVec, index);
        
        return res;
    }
};
