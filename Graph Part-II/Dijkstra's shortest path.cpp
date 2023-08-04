#include <bits/stdc++.h>
// using priority queue 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int, int>> adj[vertices];
    for(int i=0 ; i<edges ; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int>dist(vertices, INT_MAX), parent(vertices);
    for(int i=0 ; i<vertices ; i++) {
        parent[i] = i;
    }

    dist[source] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int> > > pq;
    pq.push({0, source});

    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int nodeVal = node.second;
        int nodeWeight = node.first;

        for(auto x: adj[nodeVal]) {
            int adjNode = x.first;
            int adjWeight = x.second;

            if(dist[adjNode] >nodeWeight + adjWeight) {
                dist[adjNode] = nodeWeight + adjWeight;
                parent[adjNode] = nodeVal;
                pq.push({dist[adjNode] , adjNode});
            }
        }
    }

    return dist;
}
