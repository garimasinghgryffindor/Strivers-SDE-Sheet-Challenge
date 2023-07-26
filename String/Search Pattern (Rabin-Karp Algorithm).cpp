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


// OPTIMAL SEARCHING
// RABIN-KARP ALGORITHM
int bpow(int a,int b,int p){
    int ans = 1;
    while(b){
        if(b&1) ans = (a*1ll*ans)%p;
        a = (a*1ll*a)%p;
        b>>=1;
    }
    return ans;
}

vector<int> stringMatch(string text, string pattern) {
	vector<int> ans;
    int p = 5381;
    int k = pattern.length();
    int n = text.length();

    //Calculate hash of pattern
    int idealHash = 0, currHash = 0;
    for(int i=0;i<k;i++){
        int cvalue = pattern[i]-'a'+1;
        idealHash = (idealHash+(cvalue*bpow(26,k-i-1,p)%p)%p)%p;
        cvalue = text[i]-'a' + 1;
        currHash = (currHash + (cvalue*bpow(26,k-i-1,p)%p)%p)%p;
    }

    for(int i=k ; i<=n ; i++){
        if(idealHash==currHash){
            //Check whether it matches pattern char by char
            bool flag = true;
            for(int j=0;j<k;j++){
                if(pattern[j]!=text[i-k+j]){
                    flag = false;
                    break;
                }       
            }
            if(flag) ans.push_back(i-k+1);        //1 based indexing
        }

        //Window Slide
        if(i==n) break;
        int cvalue = text[i-k]-'a'+1;
        currHash = (currHash - (cvalue*bpow(26,k-1,p)%p)%p + 0ll +  p)%p;
        currHash = (currHash *1ll*26)%p;
        cvalue = text[i]-'a'+1;
        currHash = (currHash + cvalue)%p;
    }
    return ans;
}


