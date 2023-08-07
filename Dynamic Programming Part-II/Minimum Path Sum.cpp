// USING RECURSION
// trying all the paths
// and finding the minimum cost
int recur(vector<vector<int>>&grid, int i, int j) {
    if(i == 0 && j == 0) return grid[i][j];
    // there are 2 postions we can go to -> left and top
    // go left
    int left = INT_MAX;
    if(j-1 >= 0)
        left = grid[i][j] + recur(grid,i,j-1);
    // go top
    int top = INT_MAX;
    if(i-1 >= 0)
        top = grid[i][j] + recur(grid,i-1,j);

    return min(left, top);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    return recur(grid, n-1 ,m-1);
}


// USING MEMOIZATION
// trying all the paths
// and finding the minimum cost
int recur(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp) {
    if(i == 0 && j == 0) return grid[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    // there are 2 postions we can go to -> left and top
    // go left
    int left = INT_MAX;
    if(j-1 >= 0)
        left = grid[i][j] + recur(grid,i,j-1,dp);
    // go top
    int top = INT_MAX;
    if(i-1 >= 0)
        top = grid[i][j] + recur(grid,i-1,j,dp);

    return dp[i][j] = min(left, top);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return recur(grid, n-1 ,m-1,dp);
}


