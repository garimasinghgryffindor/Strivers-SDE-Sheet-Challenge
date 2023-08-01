#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int>res;
    map<int,int>mp;
    for(int i=0 ; i<k ; i++) {
        mp[arr[i]]++;
    }

    int count = mp.size();

    res.push_back(count);
    for(int i=k ; i<arr.size() ; i++) {
        mp[arr[i-k]]--;
        if(mp[arr[i-k]] == 0) {
            mp.erase(arr[i-k]);
        }

        mp[arr[i]]++;
        count = mp.size();

        res.push_back(count);
    }

    return res;
}
