Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.


my first approach

Using maps to keep track of rows and columns


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int , int> r , c;
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[0].size() ; j++){
                if(matrix[i][j]==0){
                    r[i] = 2;
                    c[j] = 2;
                }
            }
        }
        
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[0].size() ; j++){
                if(r[i]==2 || c[j]==2){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



2) second approach

Space optimization

We can use the first row and first column of the matrix as map has been used in the previous solution ..
