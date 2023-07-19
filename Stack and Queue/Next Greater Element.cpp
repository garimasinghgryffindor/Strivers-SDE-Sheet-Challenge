#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int>greater;
    stack<int>st;
    for(int i=n-1 ; i>=0 ; i--) {
        if(st.empty()) {
            greater.push_back(-1);
            st.push(arr[i]);
            continue;
        }

        if(arr[i] < st.top()) {
            greater.push_back(st.top());
            st.push(arr[i]);
        } else {
            while(!st.empty()) {
                if(arr[i] < st.top()) {
                    break;
                }
                st.pop();
            }
            if(st.empty()) {
                greater.push_back(-1);
            } else {
                greater.push_back(st.top());
            }
            st.push(arr[i]);
        }
    }

    reverse(greater.begin(), greater.end());

    return greater;
}
