vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int>res;
    vector<bool>visited(n,false);
    queue<int>q;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(visited[curr]) {
            continue;
        }
        res.push_back(curr);
        visited[curr] = true;
        for(int x: adj[curr]) {
            q.push(x);
        }
    }

    return res;
}
