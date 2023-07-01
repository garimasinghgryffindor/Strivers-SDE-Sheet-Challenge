Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.


    
Brute Force

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	// BRUTE FORCE
	int r = matrix.size();
	int c = matrix[0].size();
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			if(matrix[i][j] == 0) {
				// marking elements in the row -1
				for(int k=0 ; k<c ; k++) {
                    // checking if the element is already zero or not
                    // make it -1 only when it is not 0
					if(matrix[i][k] != 0)
						matrix[i][k] = -1;
				}

				// marking elements in the col -1
				for(int k=0 ; k<r ; k++) {
                    // checking if the element is already zero or not
                    // make it -1 only when it is not 0
					if(matrix[k][j]!=0)
						matrix[k][j] = -1;
				}
			}
		}
	}

	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			if(matrix[i][j] == -1) {
				matrix[i][j] = 0;
			}
		}
	}
}

    

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



	void setZeros(vector<vector<int>> &matrix)
{
	int r = matrix.size();
	int c = matrix[0].size();
	// HERE WE ARE USING THE FIRST ROW AND FIRST COLUMN TO KEEP TRACK OF 0's
	// instead of that extra space we used in the previous approach
	int col0 = -1;
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			if(matrix[i][j] == 0) {
				matrix[i][0] = 0;
				if(j!=0) {
					matrix[0][j] = 0;
				} else {
					col0 = 0;
				}
			}
		}
	}

	for(int i=1 ; i<r ; i++) {
		for(int j=1 ; j<c ; j++) {
			if(matrix[i][j]!=0 && (matrix[i][0] == 0 || matrix[0][j] == 0)) {
				matrix[i][j] = 0;
			}
		}
	}

	if(matrix[0][0] == 0) {
		// for the row
		for(int i=0 ; i<c ; i++) {
			matrix[0][i] = 0;
		}
	}

	if(col0 == 0) {
		for(int i=0 ; i<r ; i++) {
			matrix[i][0] = 0;
		}
	}
	
}
