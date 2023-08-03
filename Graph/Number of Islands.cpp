// NOTE :  CHECK OUT THIS OTHER PROBLEM AS WELL CALLED AS NUMBER OF DISTINCTTTT ISLANDS
// NOTE
// NOTE

// basically using BFS 
int numIslands(vector<vector<char>>& grid) {
    vector<vector<bool>> visit(grid.size(),vector<bool>(grid[0].size(),false));
    int count = 0;
    queue<pair<int,int>> q;

    for(int  i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
         if(visit[i][j] || grid[i][j]=='0')continue;
            q.push({i,j});
            count++;
            while(q.size()){
                int u = q.front().first;
                int v = q.front().second;
                q.pop();
                if(u>=grid.size() || u<0 || v>=grid[0].size() || v<0 || visit[u][v] || grid[u][v]=='0')continue;
                visit[u][v] = true; 
               q.push({u+1,v});
               q.push({u-1,v});
               q.push({u,v+1});
               q.push({u,v-1}); 
            }  
        }   
    }
    

    return count;
}



class Solution {
public:
    // USING DFS
    void dfs(vector<vector<char>>&graph, int r, int c, vector<vector<bool>>&visited) {
        visited[r][c] = true;
        
        vector<int>rows = {-1, 0, 1, 0};
        vector<int>cols = {0, 1, 0, -1};
        
        for(int i=0 ; i<4 ; i++) {
            if(r+rows[i]>=0 && r+rows[i]<graph.size() && c+cols[i]>=0 && c+cols[i]<graph[0].size()) {
                if(graph[r+rows[i]][c+cols[i]] == '1' && !visited[r+rows[i]][c+cols[i]]) {
                    graph[r+rows[i]][c+cols[i]] = '0';
                    dfs(graph, r+rows[i], c+cols[i], visited);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int count = 0;
        
        for(int i=0 ; i<r ; i++) {
            for(int j=0 ; j<c ; j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
