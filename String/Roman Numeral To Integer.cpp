int romanToInt(string s) {
    unordered_map<char,int>mp;
    mp['I']=1, mp['V']=5, mp['X']=10, mp['L']=50, mp['C']=100, mp['D']=500,mp['M']=1000;
    int ans = 0;
    int n = s.length();
    for(int i=0 ; i<n ; i++) {
        if(i==0) {
            ans += mp[s[i]];
        } else {
            if(mp[s[i]] <= mp[s[i-1]]) {
                ans += mp[s[i]];
            } else {
                ans -= mp[s[i-1]];
                int temp = mp[s[i]]-mp[s[i-1]];
                ans += temp;
            }
        }
    }

    return ans;
}
