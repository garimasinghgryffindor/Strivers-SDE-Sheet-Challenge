Combination Sum II – Find all unique combinations

Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.


Solution 1: Using extra space and time complexity 
Approach:
Defining the Recursive Function:

void recur(vector<int>arr,int target,int sum,int idx,vector<vector<int>>&res,vector<int>temp) {
    if(sum > target)
        return;
    if(sum == target) {
        res.push_back(temp);
        return;
    }

    for(int i=idx ; i<arr.size() ; i++) {
        if(i!=idx && arr[i-1] == arr[i]) {
            continue;
        }
        if(arr[i]+sum > target)
            break;
        temp.push_back(arr[i]);
        recur(arr,target,sum+arr[i],i+1,res,temp);
        temp.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    vector<int> temp;
    recur(arr,target,0,0,res,temp);

    return res;
}
