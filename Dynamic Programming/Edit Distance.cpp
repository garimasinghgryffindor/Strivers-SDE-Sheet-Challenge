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
