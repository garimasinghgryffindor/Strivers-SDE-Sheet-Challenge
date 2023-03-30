Search in a sorted 2D matrix

Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

Given matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row


Solution 1: Naive approach
Approach: We can traverse through every element that is present in the matrix and return true if we found any element in the matrix is equal to the target integer. If the traversal is finished we can directly return false as we did not find any element in the matrix to be equal to the target integer.
Time complexity: O(m*n)
Space complexity: O(1)


Solution 2: [Efficient] – Binary search
Intuition: As it is clearly mentioned that the given matrix will be row-wise and column-wise sorted, we can see that the elements in the matrix will be in a monotonically increasing order. So we can apply binary search to search the matrix. Consider the 2D matrix as a 1D matrix having indices from 0 to (m*n)-1 and apply binary search. Below the available image is the visual representation of the indices of 3*4 matrix.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        if(!matrix.size())
            return false;
        int high = matrix.size() * matrix[0].size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] == target)
                return true;
            
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return false;
    }};
