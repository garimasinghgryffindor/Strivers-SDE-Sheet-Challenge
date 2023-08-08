// USING RECURSION
bool recur(string s, unordered_map<string,bool>&mp, int idx) {
    if(idx >= s.length()) return true;
    
    for(int i = idx; i < s.length(); i++) {
        string curr = s.substr(idx, i-idx+1);
        if(mp[curr]) {
            // in the dictionary
            // therefore can make a recursive call
            bool ret = recur(s, mp, i+1);
            if(ret) return true;
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool> mp;
    for(string x: wordDict) {
        mp[x] = true;
    }
    
    return recur(s, mp, 0);
}



// USING MEMOIZATION
bool recur(string s,unordered_map<string,bool>&mp,int idx,vector<int>&dp) {
    if(idx >= s.length()) return true;
    
    if(dp[idx] != -1) return dp[idx];
    
    for(int i = idx; i < s.length(); i++) {
        string curr = s.substr(idx, i-idx+1);
        if(mp[curr]) {
            // in the dictionary
            // therefore can make a recursive call
            bool ret = recur(s, mp, i+1, dp);
            if(ret) return dp[idx] = true;
        }
    }
    return dp[idx] = false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    vector<int>dp(s.length(), -1);
    unordered_map<string,bool> mp;
    for(string x: wordDict) {
        mp[x] = true;
    }
    
    return recur(s, mp, 0, dp);
}







