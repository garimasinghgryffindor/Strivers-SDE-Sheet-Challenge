class Solution {
public:
    // RECURSION
    int n,m;
    
    int recur(string&s1, string&s2, int i, int j) {
        if(i >= n) {
            return (m-j);
        }
        if(j >= m) {
            return (n-i);
        }
        
        if(s1[i] == s2[j]) {
            return 0 + recur(s1, s2, i+1, j+1);
        }
        
        return 1+min({recur(s1,s2,i+1,j+1), recur(s1,s2,i+1,j), recur(s1,s2,i,j+1) });
    }
    
    int minDistance(string word1, string word2) {
        n = word1.length(), m = word2.length();
        
        return recur(word1, word2, 0, 0);
    }
};


// other way
class Solution {
public:
    // RECURSION
    int n,m;
    
    int recur(string&s1, string&s2, int i, int j) {
        if(i < 0) {
            return (j+1);
        }
        if(j < 0) {
            return (i+1);
        }
        
        if(s1[i] == s2[j]) {
            return 0 + recur(s1, s2, i-1, j-1);
        }
        
        return 1+min({recur(s1,s2,i-1,j-1), recur(s1,s2,i-1,j), recur(s1,s2,i,j-1) });
    }
    
    int minDistance(string word1, string word2) {
        n = word1.length(), m = word2.length();
        
        return recur(word1, word2, n-1, m-1);
    }
};



class Solution {
public:
    // MEMOIZATION
    vector<vector<int>>dp;
    
    int recur(string&s1, string&s2, int i, int j) {
        if(i < 0) {
            return (j+1);
        }
        if(j < 0) {
            return (i+1);
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
            return 0 + recur(s1, s2, i-1, j-1);
        }
        
        return dp[i][j] = 1+min({recur(s1,s2,i-1,j-1), recur(s1,s2,i-1,j), recur(s1,s2,i,j-1) });
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        
        dp.resize(n, vector<int>(m, -1));
        
        return recur(word1, word2, n-1, m-1);
    }
};


class Solution {
public:
    // TABULATION
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 0 ; i<=n ; i++) {
            dp[i][0] = i;
        }
        
        for(int j=0 ; j<=m ; j++) {
            dp[0][j] = j;
        }
        
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1+min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                }
            }
        }
        
        return dp[n][m];
    }
};
