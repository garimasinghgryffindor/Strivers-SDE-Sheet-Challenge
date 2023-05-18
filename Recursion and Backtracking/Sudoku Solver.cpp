Sudoku Solver

Given a 9×9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.
         1. All the rows should be filled with numbers(1 – 9) exactly once.
         2. All the columns should be filled with numbers(1 – 9) exactly once.
         3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.



Solution: using Recursion and Backtracking


// BRUTE FORCE

class Solution {
public:
    void recur(vector<vector<char>>&board,int row,int col,bool&flag) {
        if(col == 9) {
            flag = true;
            return;
        }
        
       if(row == 9) {
           recur(board,0,col+1,flag);
           return;
       }
        
        if(flag)
            return;
        
        if(board[row][col]!='.') {
            recur(board,row+1,col,flag);
            return;
        }

        // checking whether all 1 to 9 are valid for row and col

        // to be putted at at index => (row, col)
        // what elements we can put => (0, 9)
        // we are determing the valid values 
        // and recursively calling function there
        
        for(int i=1 ; i<=9 ; i++) {
            bool valid = true;
            // i's are the possible values that can be inserted there
            // we are checking for the value i's validity at the current index
            for(int j=0 ; j<9 ; j++) {
                if(board[row][j]=='0'+i) {
                    valid = false;
                    break;
                }
                if(board[j][col]=='0'+i) {
                    valid = false;
                    break;
                }
            }
            
            int x = row/3;
            int y = col/3;
            
            for(int k=x*3 ; k<x*3+3 ; k++) {
                for(int l=y*3 ; l<y*3+3 ; l++) {
                    if(board[k][l]=='0'+i) {
                        valid = false;
                        break;
                    }
                }
                if(!valid)
                    break;
            }

            if(valid) {
                // if valid element
                // make changes correspondingly and recursively call the function

                cout<<"i entered\n"<<i<<endl;

                board[row][col] = '0'+i;

                recur(board,row+1,col,flag);
                if(flag)
                    return;
                
                board[row][col] = '.';
            }
        }
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = false;
        int col = 0,row = 0;
        recur(board,row,col,ans);
    }
};
