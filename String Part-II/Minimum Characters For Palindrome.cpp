// NAIVE APPROACH
// O(N^2)
bool isPal(string s) {
	for(int i=0 ; i<s.length()/2 ; i++) {
		if(s[i] != s[s.length()-1-i]) {
			return false;
		}
	}
	return true;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.length();
	for(int i=n ; i>0 ; i--) {
		if(isPal(str.substr(0,i))) {
			return str.length()-i;
		}
	}

	return str.length()-1;
}


// OPTIMAL
int minCharsforPalindrome(string str) {
	int n = str.length();
	int i=0, j=n-1;
	int k = j;
	while(j>=i) {
		if(str[i] == str[j]) {
			i++;
			j--;
		} else {
			i = 0;
			j = k-1;
			k = j;
		}
	}

	return n-(k+1);
}


