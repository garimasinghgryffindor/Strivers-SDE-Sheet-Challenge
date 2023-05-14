Palindrome Partitioning

Problem Statement: You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.




Solution
Approach: The initial idea will be to make partitions to generate substring and check if the substring generated out of the partition will be a palindrome. Partitioning means we would end up generating every substring and checking for palindrome at every step. Since this is a repetitive task being done again and again, at this point we should think of recursion. The recursion continues until the entire string is exhausted. After partitioning, every palindromic substring is inserted in a data structure When the base case has reached the list of palindromes generated during that recursion call is inserted in a vector of vectors/list of list.
We have already discussed the initial thought process and the basic outline of the solution. The approach will get clearer with an example.
Say s = “aabb” and assume indexes of string characters to be 0-based. For a better understanding, we have divided recursion into some steps. 




bool checkPalindrome(string s) {
        for(int i=0 ; i<s.length()/2 ; i++) {
            if(s[i] != s[s.length()-1-i])
                return false;
        }
        return true;
    }
    
    void recur(string s,vector<vector<string>>&res,vector<string>temp, int idx) {
        if(idx == s.length()) {
            res.push_back(temp);
            return;
        }
        
        for(int i=idx ; i<s.length() ; i++) {
            if(checkPalindrome(s.substr(idx,i-idx+1))) {
                temp.push_back(s.substr(idx,i-idx+1));
                recur(s,res,temp,i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>temp;
        int idx = 0;
        recur(s,res,temp,idx);
        
        return res;
    }
