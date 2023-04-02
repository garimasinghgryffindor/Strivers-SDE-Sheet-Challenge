Count the number of subarrays with given xor K

Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to B.

Solution 1: Brute Force
Intuition: The brute force solution is to generate all possible subarrays. For each generated subarray we get the respective XOR and then check if this XOR is equal to B. If it is then we increment the count. In the end, we will get the count of all possible subarrays that have XOR equal to B.

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int res = 0;
    for(int i=0 ; i<n ; i++) {
        int xor1 = 0;
        for(int j=i ; j<n ; j++) {
            xor1=xor1^arr[j];
            if(xor1 == x)
                res++;
        }
    }

    return res;
}


Solution 2: Prefix XOR and map
Intuition: The main idea is to observe the prefix xor of the array. Prefix Xor is just another array, where each index contains XOR of all elements of the original array starting from index 0 up to that index. In other words prefix_xor[i] = XOR(a[0], a[1], a[2],……,a[I])


int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int res = 0;
    int xor1 = 0;

    unordered_map<int,int> mp;

    for(int i=0 ; i<n ; i++) {
        xor1=xor1^arr[i];
        if(xor1 == x)
            res++;
        
        int y = x^xor1;
        if(mp.find(y) != mp.end()) {
            res += mp[y];
        }
        mp[xor1]++;
    }

    return res;
}
