
// we are using the coloring algorithm

class Solution {
public:
    
    bool dfsUtils(vector<int>graph[],int V,vector<int>&vis,int s) {
        if(vis[s] == 1) 
            return false;
        
        if(vis[s] == 0)
        {
            vis[s] = 1;
            for(auto x: graph[s]) {
                bool res = dfsUtils(graph,V,vis,x);
                if(res == false)
                    return false;
            }
        }
        
        vis[s] = 2;
        return true;
    }
    
    bool dfs(vector<int>graph[], int V)
    {
        vector<int> vis(V,0);
        for(int i=0 ; i<V ; i++) {
            bool res = dfsUtils(graph,V,vis,i);
            if(res == false) {
                return false;
            }
        }
        
        return true;
    }
    
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        // if there's a cycle in the graph then not possible to take all courses.
        // else if there's no cycle -> possible
        vector<int>graph[V];
        for(auto x: prerequisites) {
            int u = x[0], v = x[1];
            graph[u].push_back(v);
        }
        
        return dfs(graph,V);
        
        return true;
    }

};

