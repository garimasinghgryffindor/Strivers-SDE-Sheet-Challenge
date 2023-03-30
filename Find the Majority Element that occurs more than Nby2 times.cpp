Find the Majority Element that occurs more than Nby2 times

Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.



Naive Approach: 
Approach:
The steps are as follows:
We will run a loop that will select the elements of the array one by one.
Now, for each element, we will run another loop and count its occurrence in the given array.
If any element occurs more than the floor of (N/2), we will simply return it.


int majorityElement(vector<int> v) {
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}




Solution 2 (Better):
Intuition: Use a better data structure to reduce the number of look-up operations and hence the time complexity. Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.
Approach: 
Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums) 
Here the key will be the element of the array and the value will be the number of times it occurs. 
Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2. 
If yes, return the key 
Else iterate forward.


int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
}


Optimal Approach:
Moore’s Voting Algorithm:
Apply Moore’s voting algorithm
Verify the majority element by traversing again through the array


    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = nums[0];
        for(auto x: nums) {
            if(count == 0) {
                count = 1;
                candidate = x;
            } else if(candidate == x) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
