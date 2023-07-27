// using sorting
// TC: O(NlogN)
bool areAnagram(string &str1, string &str2){
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}


// using hash map
bool areAnagram(string &str1, string &str2){
    vector<int>mp(26,0), mp2(26,0);
    for(auto x: str1) {
        mp[x-'a']++;
    }

    for(auto x: str2) {
        mp2[x-'a']++;
    }

    for(int i=0 ; i<26 ; i++) {
        if(mp[i] != mp2[i])
            return false;
    }

    return true;
}
