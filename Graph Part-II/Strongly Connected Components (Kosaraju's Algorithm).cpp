#include <bits/stdc++.h>

// using Kosaraju's Algorithm
void topologicalSort(vector<vector<int>>graph,int idx,stack<int>&st,vector<bool>&visited) {
    visited[idx] = true;

    for(int x: graph[idx]) {
        if(!visited[x])
            topologicalSort(graph, x, st, visited);
    }

    st.push(idx);
}

void dfs(vector<vector<int>>graph, vector<bool>&visited, vector<int>&res, int idx) {
    visited[idx] = true;
    res.push_back(idx);

    for(int x: graph[idx]) {
        if(!visited[x]) {
            dfs(graph, visited, res, x);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>>res;
    stack<int>st;
    vector<vector<int>>graph(n);
    for(int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
    }

    // STEP 1 TOPOLOGICAL SORT
    vector<bool>visited(n, false);
    for(int i=0 ; i<n ; i++) {
        if(!visited[i]) {
            topologicalSort(graph, i, st, visited);
        }
    }

    // STEP 2 TRANSPOSE OF THE GRAPH
    graph.clear();
    graph.resize(n);
    for(int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[v].push_back(u);
    }

    // STEP 3 MAKING DFS ON THE TRANPOSED GRAPH
    // making dfs using finish time
    vector<bool>vis(n, false);
    while(!st.empty()) {
        int tp = st.top(); st.pop();
        if(vis[tp]) continue;
        vector<int>temp;
        dfs(graph, vis, temp, tp);
        res.push_back(temp);
    }

    return res;
}


