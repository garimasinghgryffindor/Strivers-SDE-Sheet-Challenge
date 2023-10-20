Rotate Image by 90 degree

Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

Solution 1:Brute force
Approach: Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.


approach 1-> brute force
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();;
        vector<vector<int>> mat(n, vector<int>(n,0));
        
        for(int i=0 ; i<n ; i++) {
            // taking up the first row 
            // and making it the last column
            
            int col_indx = n-i-1;
            
            for(int j=0 ; j<n ; j++) {
                mat[j][col_indx] = matrix[i][j];
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                matrix[i][j] = mat[i][j];
            }
        }
        
    }
};


optimized approach
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
// */

//     TRANSPOSE
//     REVERSE ROW BY ROW
void rotate(vector<vector<int>>& matrix) {
int n = matrix.size();
for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}

for(int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
}
}
    
    
// REVERSE MATRIX
// TRANSPOSE
void rotate(vector<vector<int>>& matrix) {
reverse(matrix.begin(), matrix.end());
int n = matrix.size();
for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}
}


// CodingNinjas -> rotate - element-wise

#include <bits/stdc++.h>

// BRUTE FORCE
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<int>> newMat = mat;

    if(m==1 || n==1) {
        return;
    }

    int loop = min(m,n);

    for(int i=0 ; i<loop/2 ; i++) {
        int start_row = i;
        int start_col = i;
        int end_row = n-1-i;
        int end_col = m-1-i;
        // row-wise traversal
        for(int j=start_col ; j<end_col ; j++) {
            int nextPos = j+1;
            newMat[start_row][nextPos] = mat[start_row][j];
        }
       
        // col-wise traversal
        for(int j=start_row ; j<end_row ; j++) {
            int nextPos = j+1;
            newMat[nextPos][end_col] = mat[j][end_col];
        }
       
        // row-wise traversal
        for(int j=end_col ; j>start_col ; j--) {
            int nextPos = j-1;
            newMat[end_row][nextPos] = mat[end_row][j];
        }
        
        // col-wise traversal
        for(int j=end_row ; j>start_row ; j--) {
            int nextPos = j-1;
            newMat[nextPos][start_col] = mat[j][start_col];
        }
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            mat[i][j] = newMat[i][j];
        }
    }

}



