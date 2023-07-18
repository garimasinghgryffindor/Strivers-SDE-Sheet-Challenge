#include <bits/stdc++.h> 

// NAIVE APPROACH
// simply merging all the arrays and sorting the result
// T.C. -> NKlog(NK)


// my first approach
// let's use modified merge sort
// Time Complexity -> (K(K+1)/2)N ->K^2*N
void merge(vector<int>&left, vector<int>right) {
    int l1 = left.size(), l2 = right.size();
    vector<int>res;
    int i=0, j=0;
    while(i<l1 && j<l2) {
        if(left[i] <= right[j]) {
            res.push_back(left[i]);
            i++;
        } else {
            res.push_back(right[j]);
            j++;
        }
    }
    while(i<l1) {
        res.push_back(left[i]);
        i++;
    }
    while(j<l2) {
        res.push_back(right[j]);
        j++;
    }
    
    left.resize(l1+l2);
    for(int i=0 ; i<l1+l2 ; i++) {
        left[i] = res[i];
    }
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int>res(kArrays[0].begin(), kArrays[0].end());
    for(int i=1 ; i<k ; i++) {
        merge(res,kArrays[i]);
    }
    return res;
}



// other approach
// using priority queue
// TC-> NKlog(K) -> N*K total insertion and deletion  and logK for 1 insertion/deletion
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0 ; i<k ; i++) {
        for(auto x: kArrays[i]) {
            pq.push(x);
        }
    }
    vector<int>res;
    while(!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

