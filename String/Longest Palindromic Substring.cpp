
// BRUTE FORCE APPROACH
// FINDING ALL THE SUBSTRINGS
// AND CHECKING WHETHER THEY ARE PALINDROME OR NOT
bool isPalindrome(string s) {
    string rev = s;
    reverse(s.begin(), s.end());
    if(s == rev)
        return true;
    return false;
}
string longestPalinSubstring(string str) {
    string longest = "";
    int n = str.length();
    for(int i=0 ; i<n ; i++) {
        string temp = "";
        for(int j=i ; j<n ; j++) {
            temp += str[j];
            if(isPalindrome(temp) && longest.length() < temp.length()) {
                longest = temp;
            } 
        }
    }

    return longest;
}


// DP
string longestPalinSubstring(string str) {
    int n = str.length();
    bool dp[n][n];
    int maxLength = 0, start = 0;
    memset(dp, 0, sizeof(dp));
    for(int i=0 ; i<n ; i++) {
        dp[i][i] = true;
        maxLength = 1;
    }
    for(int i=0 ; i<n-1 ; i++) {
        if(str[i]==str[i+1]) {
            dp[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for(int i=3 ; i<=n ; i++) {
        for(int j=0 ; j<n-i+1 ; j++) {
            int k = i+j-1;
            if(dp[j+1][k-1] && str[j]==str[k]) {
                dp[j][k] = true;
                if(maxLength < i) {
                    start = j;
                    maxLength = i;
                }
            }
        }
    }

    return str.substr(start,maxLength);
}
