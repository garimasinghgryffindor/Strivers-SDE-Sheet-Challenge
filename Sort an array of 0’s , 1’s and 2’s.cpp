1: approach using brute-force (normal sorting)

2: approach using variables to keep a count of 1’s 0’s and 2’s

3: approach using a two-pointer approach Dutch National Flag Algorithm


class Solution {
public:
    void swap(int &a, int&b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void sortColors(vector<int>& nums) {
        // using Dutch National Flag Algorithm
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid<=high) {
            // if curr is a 0
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
