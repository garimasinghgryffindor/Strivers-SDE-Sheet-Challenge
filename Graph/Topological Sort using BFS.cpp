// using BFS
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // let us create an adjacency list
    vector<int>graph[v];
    // let us create an indegree array
    vector<int>indegree(v,0);
    for(int i=0 ; i<e ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int>q;
    for(int i=0 ; i<v ; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int>res;
    while(!q.empty()) {
        int frnt = q.front();
        q.pop();
        res.push_back(frnt);

        for(int x: graph[frnt]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    return res;
}
