#include <bits/stdc++.h> 
// brute force
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int>res;
    
    for(int i=1 ; i<=n ; i++) {
        int ans = INT_MIN;
        deque<int>dq;
        for(int j=0 ; j<a.size() ; j++) {
            if(!dq.empty() && dq.front()==j-i) {
                dq.pop_front();
            }
            while(!dq.empty() && a[dq.back()] >= a[j]) {
                dq.pop_back();
            }
            dq.push_back(j);

            if(j+1 >= i) {
                ans = max(ans, a[dq.front()]);
            }
        }
        res.push_back(ans);
    }
    return res;
}


// optimal
// somewhat
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int>res;
    vector<int>temp(a.begin(), a.end());
    int ele = *max_element(a.begin(), a.end());
    res.push_back(ele);

    for(int i=2 ; i<=n ; i++) {
        int ans = INT_MIN;
        for(int j=0 ; j<=a.size()-i ; j++) {
            if(temp[j] > temp[j+1]) {
                temp[j] = temp[j+1];
            }
            ans = max(ans, temp[j]);
        }
        res.push_back(ans);
    }
    return res;
}
