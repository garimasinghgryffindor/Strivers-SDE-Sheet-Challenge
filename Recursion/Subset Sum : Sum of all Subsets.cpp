Subset Sum : Sum of all Subsets (Recursion)

Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.


Solution 1: Using recursion
Intuition: The main idea is that on every index you have two options either to select the element to add it to your subset(pick) or not select the element at that index and move to the next index(non-pick).

Approach: Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e add the element to the sum or don’t pick and move to the next element, recursively, until the base condition. Here when you reach the end of the array is the base condition.



void recur(vector<int>num,vector<int>&res,int i,int sum) {
    if(i==num.size()){
        res.push_back(sum);
        return;
    }

    recur(num,res,i+1,sum);
    recur(num,res,i+1,sum+num[i]);
}

vector<int> subsetSum(vector<int> &num)
{
    // using recursion
    vector<int> res;
    recur(num,res,0,0);

    sort(res.begin(),res.end());

    return res;
}

