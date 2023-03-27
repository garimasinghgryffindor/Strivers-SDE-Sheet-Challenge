Problem Statement: Given an integer N, return the first N rows of Pascal’s triangle.
In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:


1st approach

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> vec;
        
        for(int i=0 ; i<numRows ; i++) {
            if(i==0) {
                vec.push_back({1});
            } 
            else {
                vector<int> curr;
                curr.push_back(1);
                for(int j=0 ; j<i-1 ; j++) {
                    curr.push_back(vec[i-1][j]+vec[i-1][j+1]);
                }
                curr.push_back(1);
                
                vec.push_back(curr);
            }
        }
        
        return vec;
    }
};
