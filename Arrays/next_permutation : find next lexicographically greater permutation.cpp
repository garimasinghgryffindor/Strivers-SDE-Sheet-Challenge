Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.


1st approach is BRUTE FORCE -> which is generating all the possible permutations and then directly finding the next permutation

void swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void recur(vector<int>temp,int i,int n,vector<vector<int> >&permut) {
    if (i == n) {
        permut.push_back(temp);
        return;
    }

    for(int j=i ; j<n ; j++) {
        swap(temp[i], temp[j]);
        recur(temp,i+1,n,permut);
        swap(temp[i], temp[j]);
    }
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // BRUTE FORCE
    // generating all possible perut
    vector<vector<int> > permut;
    vector<int> temp(permutation);
    sort(temp.begin(),temp.end());
    recur(temp,0,n,permut);
    sort(permut.begin() , permut.end());

    for(int i=0 ; i<permut.size() ; i++) {
        if(permut[i] == permutation && i+1 < permut.size()) {
            return permut[i+1];
        }
        if(permut[i] == permutation && i+1 <= permut.size()) {
            return permut[0];
        }
    }

    return {};
}


2)   2nd approach is in linear time complexity (mostly)

Steps->

find first index where a[i] < a[i+1]  from the end => ind1
Find first index from the end where a[j] > a[ind1] = > ind2
swap(a[ind1] and a[ind2]
reverse(ind1+1, last) 

class Solution {
public:
    void swap(int &a , int &b){
        int temp=a;
        a = b;
        b = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n=nums.size() , f=0;
        
        int i;
        //find first index where a[i] < a[i+1]  from the end => ind1
        for(i=n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                f=1;
                break;
            }
        }
        
        int ind1 = i;
        
        if(f==1)
        for(int j=n-1 ; j>ind1 ; j--){
            if(nums[j] > nums[ind1])
            {
                swap(nums[j] , nums[ind1]);
                break;
            }
        }
    
        reverse(nums.begin()+ind1+1 , nums.end());
    }
};
