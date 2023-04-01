Length of the longest subarray with zero Sum

Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Solution 1 (Naive approach) :
Intuition:
We are required to find the longest subarray that sums to zero. So our initial approach could be to consider all possible subarrays of the given array and check for the subarrays that sum to zero. Among these valid subarrays (a sum equal to zero) we’ll return the length of the largest subarray by maintaining a variable, say max.   
Approach :  
Initialize a variable max = 0, which stores the length of the longest subarray with sum 0.
Traverse the array from start and initialize a variable sum = 0 which stores the sum of the subarray starting with the current index
Traverse from the next element of current_index up to the end of the array, each time add the element to the sum and check if it is equal to 0.
If sum = 0, check if the length of the subarray so far is > max and if yes update max
Now keep adding elements and repeat step 3 a.
After the outer loop traverses all elements return max

static int solve(int[] a){
	int  max = 0;
	for(int i = 0; i < a.length; ++i){
		int sum = 0;
		for(int j = i; j < a.length; ++j){
			sum += a[j];
			if(sum == 0){
				max = Math.max(max, j-i+1);
			}
		}
	}
	return max;
   }



Solution 2 (Optimised Approach):
Intuition:  Now let’s say we know that the sum of subarray(i, j) = S, and we also know that the sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.
Let us understand the above statement clearly,
So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have the same prefix sum, we can conclude that the 2nd part of this subarray sums to zero
Now let’s understand the approach
Approach: 
First, let us initialize a variable say sum = 0 which stores the sum of elements traversed so far and another variable says max = 0 which stores the length of the longest subarray with sum zero.
Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as a key and its index as a value.
Now traverse the array, and add the array element to our sum. 
 (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0,      so we update max with the maximum value of (max, current_index+1)
(ii)  If the sum is not equal to zero then we check the hashmap if we’ve seen a subarray with this sum before
if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our max 
else -> Insert (sum, current_index) into hashmap to store prefix sum until the current index
After traversing the entire array our max variable has the length of the longest substring having a sum equal to zero, so return max.
NOTE: we do not update the index of a sum if it’s seen again because we require the length of the longest subarray.


int maxLen(vector<int>&A, int n)
    {   
        int mx=0;
        
        // using prefix sum;
        vector<int>prefixSum(n,0);
        unordered_map<int,int>mp;
        prefixSum[0] = A[0];
        int sum = 0; 
        for(int i=0 ; i<n ; i++) {
            sum += A[i]; 
            prefixSum[i] = sum;
            
            if(sum == 0) {
                mx = i+1;
            }
            
            if(mp.find(sum) != mp.end() ) {
                mx = max(mx, i-mp[prefixSum[i]]);
            }
            else 
                mp[prefixSum[i]] = i;
        }   
        
        return mx;
    }

