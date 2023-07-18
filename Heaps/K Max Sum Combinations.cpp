#include <bits/stdc++.h>

// NAIVE APPROACH
// my first approach
// GETTING ALL THE SUMS
// AND SORTING ALL THE VALUES
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    vector<int>sumV;
	for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            int sum = a[i] + b[j];
            sumV.push_back(sum);
        }
    }
    sort(sumV.rbegin(), sumV.rend());
    vector<int>res(k);
    copy(sumV.begin(), sumV.begin()+k,res.begin());
    return res;
}


// NAIVE APPROACH
// USING PRIORITY QUEUE
// Time Complexity: O(N^2*log(N^2))
// Auxiliary Space : O(N^2)
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<int>pq;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            pq.push(a[i]+b[j]);
        }
    }

    vector<int>res;
    int x = 0;
    while(x < k) {
        res.push_back(pq.top());
        pq.pop();
        x++;
    }

    return res;
}



// OPTIMAL APPROACH
// USING PRIORITY QUEUE
// Time Complexity : O(N log N) assuming K <= N
// Auxiliary Space : O(N)
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    vector<int>res;

    // sorting in descending order
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    set<pair<int,int>> st;
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push({a[0]+b[0], {0, 0}});

    int x = 0;
    while(x < k) {
        x++;
        res.push_back(pq.top().first);
        pair<int,pair<int,int> > itr = pq.top();
        pq.pop();
        int i = itr.second.first;
        int j = itr.second.second;
        int sum = a[i] + b[j + 1];

        if(st.find({i, j+1}) == st.end()) {
            pq.push({sum, {i, j+1}});
            st.insert({i, j+1});
        }

        sum = a[i + 1] + b[j];

        if(st.find({i+1, j}) == st.end()) {
            pq.push({sum, {i+1, j}});
            st.insert({i+1, j});
        }

    }
    
    return res;
}

