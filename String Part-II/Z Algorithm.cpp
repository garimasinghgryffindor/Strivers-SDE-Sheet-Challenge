// NAIVE
int zAlgorithm(string s, string p, int n, int m)
{
	// we will create a Z-Array
	// POV: Also do the KMP algorithm for String Pattern Matching
	string newString = p + '$' + s;
	int len = newString.length();
	int res = 0;

	vector<int>z(len,0);
	for(int i=1 ; i<len ; i++) {
		int k=i;
		for(int j=0 ; j<len-i ; j++) {
			if(newString[k] == newString[j]) {
				k++;
			} else {
				break;
			}
		}
		z[i] = k-i;
		if(z[i] == p.length()) {
			res++;
		}
	}

	return res;
}



// OPTIMAL
int zAlgorithm(string s, string p, int n, int m)
{
	// we will create a Z-Array
	// POV: Also do the KMP algorithm for String Pattern Matching

	string str = p + '$' + s;
	int l = str.length();
	int res = 0;

	int L = 0, R = 0, k;

	vector<int>z(l,0);

	for(int i=1 ; i<l ; ++i) {
		if (i > R)
        {
            L = R = i;

            while (R<l && str[R-L] == str[R])
                R++;
            z[i] = R-L;
            R--;
        } else {
			k = i-L;
			if (z[k] < R-i+1)
                z[i] = z[k];
			else {
				L = i;
                while (R<l && str[R-L] == str[R])
                    R++;
                z[i] = R-L;
                R--;
			}
		}
	}

	for(int i=0 ; i<l ; ++i) {
		if(z[i] == p.length()) {
			res++;
		}
	}

	return res;
}

