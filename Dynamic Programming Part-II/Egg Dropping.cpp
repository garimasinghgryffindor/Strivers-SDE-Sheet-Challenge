//VARIATION OF MCM PROBLEM

// using RECURSION
int eggDrop(int n, int k) 
{
    if(k == 0 || k == 1) return k;
    if(n == 1) return k;
    
    int mn = INT_MAX;
    for(int i = 1; i <= k; i++) {
        int ifBreaks = 1 + eggDrop(n-1, i-1);
        int ifNotBreaks = 1 + eggDrop(n, k-i);
        int breaks = max(ifBreaks, ifNotBreaks); // in worst case
        mn = min(breaks, mn); // minimum number of attempts
    }
    
    return mn;
}


// using MEMOIZATION
int recur(int n, int k, vector<vector<int>>&dp) 
{
    if(k == 0 || k == 1) return k;
    if(n == 1) return k;
    
    if(dp[n][k] != -1) return dp[n][k];
    
    int mn = INT_MAX;
    for(int i = 1; i <= k; i++) {
        int ifBreaks = 1 + recur(n-1, i-1, dp);
        int ifNotBreaks = 1 + recur(n, k-i, dp);
        int breaks = max(ifBreaks, ifNotBreaks); // in worst case
        mn = min(breaks, mn); // minimum number of attempts
    }
    
    return dp[n][k] = mn;
}
int eggDrop(int n, int k) 
{
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    return recur(n,k, dp);
}



// using TABULATION
int eggDrop(int n, int k) 
{
    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
    for(int i = 0; i <= k; i++) dp[1][i] = i;
    for(int i = 0; i <= n; i++) { dp[i][0] = 0; dp[i][1] = 1; }
    
    for(int floor = 2; floor <= k; floor++) {
        for(int eggs = 2; eggs <= n; eggs++) {
            int mn = INT_MAX;
            for(int i = 1; i <= floor; i++) {
                int ifBreaks = 1 + dp[eggs-1][i-1];
                int ifNotBreaks = 1 + dp[eggs][floor-i];
                int breaks = max(ifBreaks, ifNotBreaks); // in worst case
                mn = min(breaks, mn); // minimum number of attempts
            }
            
            dp[eggs][floor] = mn;
        }
    }
    
    return dp[n][k];
}


