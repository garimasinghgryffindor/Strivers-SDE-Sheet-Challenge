
class Solution {
public:
    // using BFS
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>colors(v, -1);
        queue<int>q;
        
        for(int i=0 ; i<v ; i++) {
            if(colors[i] != -1) continue;
            colors[i] = 0;
            q.push(i);
            
            while(!q.empty()) {
                int frnt = q.front();
                q.pop();
                int color = colors[frnt];

                for(int x: graph[frnt]) {
                    if(colors[x] == color) return false;
                    else if(colors[x] == -1) {
                        colors[x] = 1 - color;
                        q.push(x);
                    }
                }
            }
        }
        
        return true;
    }
};
