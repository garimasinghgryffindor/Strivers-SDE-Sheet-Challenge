// using DFS
void dfs(vector<int>graph[],int idx, vector<bool>&vis,stack<int>&st) {
    vis[idx] = true;

    for(int x: graph[idx]) {
        if(!vis[x]) {
            dfs(graph,x,vis,st);
        }
    }
    st.push(idx);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // let us create an adjacency list
    vector<int>graph[v];
    for(int i=0 ; i<e ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
    }

    vector<bool>visited(v,false);
    stack<int>st;
    for(int i=0 ; i<v ; i++) {
        if(!visited[i]) {
            dfs(graph, i, visited,st);
        }
    }

    vector<int>res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}
