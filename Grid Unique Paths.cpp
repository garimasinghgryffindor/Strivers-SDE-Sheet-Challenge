Grid Unique Paths | Count paths from left-top to the right bottom of a matrix

Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

Approach: (Recursive) The problem states that we can either move rightward or downward direction. So we recursively try out all the possible combinations.

	int countPaths(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }



Approach: (Memoization)
Step 1: Take a dummy matrix A[ ][ ]  of size m X n and fill it with -1. 

int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }




Approach: (Tabulation)

int uniquePaths(int m, int n) {
        int res = 0;
        vector<vector<int>>dp(m, vector<int>(n,1));
        for(int i=1 ; i<m ; i++) {
            for(int j=1 ; j<n ; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
}







Solution 3: Combinatorics Solution

Intuition: If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number of steps to reach the end.

Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

Approach: The approach of this solution is very simple just use a for loop to calculate the m+n-2Cn-1  or m+n-2Cm-1 



int uniquePaths(int m, int n) {
        // m+n-2Cn-1  or m+n-2Cm-1 
        int N = m+n-2;
        int r = n-1;
        long long res = 1;
        for(int i=1 ; i<=r ; i++) {
            res = res*(N-r+i)/i;
        }
        
        return res;
    }
