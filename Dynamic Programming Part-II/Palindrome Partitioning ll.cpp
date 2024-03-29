// using RECURSION
bool chkPalindrome(string s) {
    for(int i=0 ; i<s.length()/2 ; i++) {
        if(s[i] != s[s.length() - i -1]) return false;
    }
    return true;
}
int recur(string str, int idx, int n) {
    if(idx == n) return 0;

    int mn = INT_MAX;
    for(int k = idx; k < n; k++) {
        string curr = str.substr(idx, k-idx+1);
        if(chkPalindrome(curr)) {
            int cuts = 1 + recur(str, k+1, n);
            mn = min(cuts, mn);
        }
    }
    return mn;
}
int palindromePartitioning(string str)
{
    int n = str.length();
    return recur(str, 0, n) - 1;
}


// using MEMOIZATION
bool chkPalindrome(string s) {
    for(int i=0 ; i<s.length()/2 ; i++) {
        if(s[i] != s[s.length() - i -1]) return false;
    }
    return true;
}
int recur(string str, int idx, int n, vector<int>&dp) {
    if(idx == n) return 0;

    if(dp[idx] != -1) return dp[idx];

    int mn = INT_MAX;
    for(int k = idx; k < n; k++) {
        string curr = str.substr(idx, k-idx+1);
        if(chkPalindrome(curr)) {
            int cuts = 1 + recur(str, k+1, n, dp);
            mn = min(cuts, mn);
        }
    }
    return dp[idx] = mn;
}
int palindromePartitioning(string str)
{
    int n = str.length();
    vector<int>dp(n, -1);
    return recur(str, 0, n, dp) - 1;
}


// using TABULATION
bool chkPalindrome(string s) {
    for(int i=0 ; i<s.length()/2 ; i++) {
        if(s[i] != s[s.length() - i -1]) return false;
    }
    return true;
}
int palindromePartitioning(string str)
{
    int n = str.length();
    vector<int>dp(n+1, 0);

    for(int idx = n-1; idx >= 0; idx--) {
        int mn = INT_MAX;
        for(int k = idx; k < n; k++) {
            string curr = str.substr(idx, k-idx+1);
            if(chkPalindrome(curr)) {
                int cuts = 1 + dp[k+1];
                mn = min(cuts, mn);
            }
        }
        dp[idx] = mn;
    }

    return dp[0] - 1;
}
