
approach 1 using merge sort


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0 , j=0 ;
        vector<int>res(n+m);
        int x = 0;
        while(i<m && j<n) {
            if(nums1[i] <= nums2[j]) {
                res[x++] = nums1[i++];
            } else {
                res[x++] = nums2[j++];
            }
        }
        
        while(i<m) {
            res[x++] = nums1[i++];
        }
        while(j<n) {
            res[x++] = nums2[j++];
        }
        
        for(int i=0 ; i<n+m ; i++) {
            nums1[i] = res[i];
        }
    }
};



2)   approach 2 using merge sort + space optimization


      // let us do reverse sorting here. in that case we will not require that extra space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1 , j=n-1 ;
        int x = m+n-1;
        
        while(i>=0 && j>=0) {
            if(nums1[i] >= nums2[j]) {
                nums1[x--] = nums1[i--];
            } else {
                nums1[x--] = nums2[j--];
            }
        }
        
        while(i>=0) {
            nums1[x--] = nums1[i--];
        }
        while(j>=0) {
            nums1[x--] = nums2[j--];
        }
    }
};
