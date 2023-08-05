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



