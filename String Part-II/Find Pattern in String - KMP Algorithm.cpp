#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int n = s.length();
    int l = p.length();
    vector<int>vec(l, 0);
    int i = 1;
    int len = 0;
    while(i<l) {
        if(p[i] == p[len]) {
            len++;
            vec[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = vec[len - 1];
            } else {
                vec[i] = 0;
                i++;
            }
        }
    }
    
    i=0;
    int j=0;
    while((n-i) >= (l-j)) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        if(j == l) {
            return true;
        }
        else if(s[i] != p[j] && i<n){
        
            if(j!=0) {
                j = vec[j-1];
            } else {
                i++;
            }
        }
    }
    return false;
}
