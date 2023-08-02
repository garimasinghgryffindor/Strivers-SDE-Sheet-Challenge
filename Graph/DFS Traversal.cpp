void dfs(int idx, vector<vector<int>>graph,vector<int>&temp,vector<bool>&vis) {
    vis[idx] = true;
    temp.push_back(idx);

    for(int i : graph[idx]) {
        if(!vis[i])
            dfs(i, graph, temp, vis);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>res;
    // converting it to adjacency list
    vector<vector<int> > graph(V);
    for(int i=0 ; i<E ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool>visited(V, false);
    for(int i=0 ; i<V ; i++) {
        if(!visited[i]) {
            vector<int>temp;
            dfs(i,graph,temp,visited);
            res.push_back(temp);
        }
    }

    return res;
}
