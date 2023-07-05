Two Sum : Check if a pair with given sum exists in Array

Naive Approach(Brute-force approach): 
Intuition: For each element of the given array, we will try to search for another element such that its sum is equal to the target. If such two numbers exist, we will return the indices or “YES” accordingly.


vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}



Better Approach(using Hashing): 
Intuition: Basically, in the previous approach we selected one element and then searched for the other one using a loop. Here instead of using a loop, we will use the HashMap to check if the other element i.e. target-(selected element) exists. Thus we can trim down the time complexity of the problem.

vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> mp;
        for(int i=0 ; i<nums.size() ; i++) {
            mp.insert({nums[i], i});
        }
        
        for(int i=0 ; i<nums.size() ; i++) {
            int val = target - nums[i];
            auto itr = mp.find(val);
            if(val == nums[i]) {
                itr++;
                if(itr->first == val) {
                    return {i,itr->second};
                }
            }
            else  {
                if(itr != mp.end()) {
                    return {i, itr->second};
                }
            }
        }
        
        return{};
    }


Optimized Approach(using two-pointer): 
Intuition: In this approach, we will first sort the array and will try to choose the numbers in a greedy way.
We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right, we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the right pointer. 
If sum == target we will return either “YES” or the indices as per the question. But if the left crosses the right pointer, we will return “NO” or {-1, -1}.

Approach:
The steps are the following:
We will sort the given array first.
Now, we will take two pointers i.e. left, which points to the first index, and right, which points to the last index.
Now using a loop we will check the sum of arr[left] and arr[right] until left < right.
If arr[left] + arr[right] > sum, we will decrement the right pointer.
If arr[left] + arr[right] < sum, we will increment the left pointer.
If arr[left] + arr[right] == sum, we will return the result.
Finally, if no results are found we will return “No” or {-1, -1}.

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> newNums;
        for(int i=0 ; i<nums.size() ; i++) {
            newNums.push_back({nums[i], i});
        }
        
        sort(newNums.begin(), newNums.end());
        
        int left = 0, right = nums.size()-1;
        
        while(left < right) {
            if(newNums[left].first + newNums[right].first == target) {
                return {newNums[left].second, newNums[right].second};
            } else if(newNums[left].first + newNums[right].first < target) {
                left++;
            } else {
                right--;
            }
        }
        
        if(newNums[left].first + newNums[right].first) {
            return {newNums[left].second, newNums[right].second};
        }
        
        return {};
    }
