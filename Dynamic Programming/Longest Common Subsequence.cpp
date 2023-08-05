// using RECURSION
int n, m;
int recur(string&s1, string&s2 , int i, int j) {
    if(i>=n || j>=m) return 0;
    
    int take = 0;
    if(s1[i] == s2[j]) {
        take = 1 + recur(s1, s2, i+1 , j+1);
    }
    
    int notTake1 = 0;
    int notTake2 = 0;
    notTake1 = 0 + recur(s1, s2, i+1, j);
    notTake2 = 0 + recur(s1, s2, i, j+1);
    
    return max({take, notTake1, notTake2});
}

int longestCommonSubsequence(string text1, string text2) {
    n = text1.length(), m = text2.length();
    return recur(text1, text2, 0, 0);
}



// using MEMOIZATION
int n, m;
vector<vector<int>>dp;
int recur(string&s1, string&s2 , int i, int j) {
    if(i>=n || j>=m) return 0;
        
    if(dp[i][j] != -1) return dp[i][j];
    
    int take = 0;
    if(s1[i] == s2[j]) {
        take = 1 + recur(s1, s2, i+1 , j+1);
    }
    
    int notTake1 = 0;
    int notTake2 = 0;
    notTake1 = 0 + recur(s1, s2, i+1, j);
    notTake2 = 0 + recur(s1, s2, i, j+1);
    
    return dp[i][j] = max({take, notTake1, notTake2});
}

int longestCommonSubsequence(string text1, string text2) {
    n = text1.length(), m = text2.length();
    dp.resize(n, vector<int>(m, -1));
    return recur(text1, text2, 0, 0);
}



// using TABULATION
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(), m = text2.length();
    vector<vector<int>>dp;
    dp.resize(n+1, vector<int>(m+1, -1));
    
    for(int i=0 ; i<=n ; i++) {
        dp[i][0] = 0;
    }
    
    for(int i=0 ; i<=m ; i++) {
        dp[0][i] = 0;
    }
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}


