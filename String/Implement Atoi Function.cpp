#include <bits/stdc++.h> 
int atoi(string str) {
    int ans = 0;
    bool neg = false, numbers = false;
    if(str[0] == '-') {
        neg = true;
    }

    int n = str.length();
    for(int i=0 ; i<n ; i++) {
        if(str[i]>='0' && str[i]<='9') {
            ans = ans*10 + str[i]-'0';
            numbers = true;
        }
    }

    if(numbers) {
        if(neg) {
            ans = -1*ans;
        }
        return ans;
    } else {
        return 0;
    }

}
