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


// USING TABULATION
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool>dp(n+1, false);
        unordered_map<string,bool> mp;
        for(string x: wordDict) {
            mp[x] = true;
        }
        
        dp[n] = true;
        
        for(int idx = n-1; idx >= 0; idx--) {
            bool flag = false;
            for(int i = idx; i < n; i++) {
                string curr = s.substr(idx, i-idx+1);
                
                if(mp[curr]) {
                    // in the dictionary
                    // therefore can make a recursive call
                    bool ret = dp[i+1];
                    if(ret) { dp[idx] = true; flag = true; break;}
                }
            }
            
            if(flag) continue;
            dp[idx] = false;
        }
    
        return dp[0];
    }
};











