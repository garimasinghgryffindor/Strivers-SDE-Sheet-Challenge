#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>dist(n+1,1e9);
    dist[src] = 0;
    for(int i=0 ; i<n-1 ; i++) {
        for(auto x: edges) {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            if(dist[u]!=1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist[dest];
}
