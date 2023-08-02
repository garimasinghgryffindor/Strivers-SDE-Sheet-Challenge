class Solution {
public:
    void recur(vector<vector<int>>&res, int r,int c, int color, vector<vector<bool>>&visited,int center) {
        if(r>=res.size() || c>=res[0].size() || r<0 || c<0) {
            return;
        }
        
        if(visited[r][c]) return;
        if(res[r][c] != center) return;
        
        res[r][c] = color;
        visited[r][c] = true;
        vector<int>rows= {-1, 0, 1, 0};
        vector<int>cols = {0, 1, 0, -1};
        
        for(int i=0 ; i<4 ; i++) {
            recur(res, r+rows[i], c+cols[i], color,visited,center);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // let us use recursion
        vector<vector<int>>res = image;
        vector<vector<bool>>visited(image.size(), vector<bool>(image[0].size()));
        
        int center = image[sr][sc];
        recur(res, sr,sc, color,visited,center);
        
        return res;
    }
};
