#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    stack<pair<int,int> > st;
    int n = price.size();
    vector<int>res(n,0);
    for(int i=0 ; i<n ; i++) {
        if(st.empty()) {
            res[i] = 1;
            st.push({price[i], 1});
        } else {
            while(!st.empty() && st.top().first <= price[i]) {
                res[i] += st.top().second;
                st.pop();
            }
            res[i]++;
            st.push({price[i], res[i]});
        }
    }
    return res;
}
