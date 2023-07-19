#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    vector<int>res;
    for(int i=n-1 ; i>=0 ; i--) {
        if(st.empty()) {
            res.push_back(-1);
        }
        else {
            if(st.top() < arr[i]) {
                // we have found the smaller element
                res.push_back(st.top());
            } else {
                while(!st.empty() && st.top()>=arr[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    res.push_back(-1);
                } else {
                    res.push_back(st.top());
                }
            }
        }
        st.push(arr[i]);
    }

    reverse(res.begin(), res.end());

    return res;
}
