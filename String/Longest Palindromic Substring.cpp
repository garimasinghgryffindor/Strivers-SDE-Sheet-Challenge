
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
