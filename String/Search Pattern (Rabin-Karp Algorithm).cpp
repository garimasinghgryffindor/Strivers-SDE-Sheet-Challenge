
// NAIVE APPROACH
// TIME COMPLEXITY: O(N*S)
// ITERATIVELY SEARCHING
vector<int> stringMatch(string text, string pattern) {
	vector<int>res;
	int n = text.length();
	int l = pattern.length();
	for(int i=0 ; i<n-l+1 ; i++) {
		int flag = true;
		for(int j=0 ; j<l ; j++) {
			if(text[i+j] == pattern[j]) {
				// good enough
			} else {
				flag = false;
				break;
			}
		}
		if(flag) {
			res.push_back(i+1);
		}
	}
	return res;
}
