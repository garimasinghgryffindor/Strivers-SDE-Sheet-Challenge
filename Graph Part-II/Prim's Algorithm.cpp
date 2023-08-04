// MST
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<pair<int,int>, int > >res;
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0 ; i<m ; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    int cost = 0;
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >pq;
    vector<bool>visited(n+1, false);

    pq.push({0,{1,-1}});
    while(!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        int wt = tp.first;
        int node = tp.second.first;
        int parent = tp.second.second;
        if(visited[node] == true) continue;

        visited[node] = true;
        if(parent != -1) {
          res.push_back({{parent, node}, wt});
          cost += wt;
        }

        for(auto x: graph[node]) {
            int nd = x.first;
            int weight = x.second;
            if(!visited[nd])
                pq.push({weight, {nd, node}});
        }
    }

    return res;
}


