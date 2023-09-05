// NAIVE
O((M+N)^2)
int zAlgorithm(string s, string p, int n, int m)
{
	// NAIVE approach
	string newString = p + '$' + s;
	int len = newString.length();
	int res = 0;

	vector<int>z(len,0);

	for(int i = 0; i <len; i++) {
		int x = 0;
		for(int j = i; j < len; j++) {
			if(newString[x] == newString[j]) {
				x++;
			} else {
				break;
			}
		}
		z[i] = x;
		if(x == p.length()) res++;
	}

	return res;
}

// OPTIMAL
Time Complexity: O(m+n), where m is length of pattern and n is length of text.
Auxiliary Space: O(m+n)
int zAlgorithm(string s, string p, int n, int m)
{
	// OPTIMAL approach
	string newString = p + '$' + s;
	int len = newString.length();
	int res = 0;

	vector<int>z(len,0);
	int L = 0,R = 0;

	for(int i = 1; i < len; i++) {
		if(i > R) {
			L = R = i;
			while(R < len && newString[R] == newString[R-L]) {
				R++;
			}
			z[i] = R-L;
			R--;
		} else {
			// in the range
			// we can use the already stored values; (i am saying "CAN")
			// can only use when i + z[] < R
			int k1 = i - L;
			if(i + z[k1] - 1 < R) {
				// using already computed values
				z[i] = z[k1];
			} else {
				// recalculating because matched index went beyond range. basically we have not checked there already
				L = i;
				while(R < len && newString[R] == newString[R-L]) {
					R++;
				}
				z[i] = R-L;
				R--;
			}
		}

		if(z[i] == p.length()) res++;
	}

	return res;
}
