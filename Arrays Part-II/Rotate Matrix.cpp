Rotate Image by 90 degree

Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

Solution 1:Brute force
Approach: Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.


// approach 1-> brute force
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();;
//         vector<vector<int>> mat(n, vector<int>(n,0));
        
//         for(int i=0 ; i<n ; i++) {
//             // taking up the first row 
//             // and making it the last column
            
//             int col_indx = n-i-1;
            
//             for(int j=0 ; j<n ; j++) {
//                 mat[j][col_indx] = matrix[i][j];
//             }
//         }
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<n ; j++) {
//                 matrix[i][j] = mat[i][j];
//             }
//         }
        
//     }
// };




optimized approach
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/

class Solution {
public:
    void swap(int &a,int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // reversing-> upside down (ikr)
        reverse(matrix.begin(), matrix.end());
        
        // swapping the symmetry
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
    }
};
