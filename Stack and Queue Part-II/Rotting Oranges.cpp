// using BFS
// using queue
// there are multiple source points
// SC
#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int,pair<int,int> > > q;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(grid[i][j] == 2) {
                // rotten orange
                q.push({0,{i, j}});
            }
        }
    }

    int mx = 0;
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, 1, 0, -1};
    while(!q.empty()) {
        int time = q.front().first;
        if(time > mx) {
            mx = time;
        }
        int x = q.front().second.first;
        int y = q.front().second.second;
        // neighbouring indexes
        for(int i=0 ; i<4 ; i++) {
            int xidx = x+rows[i], yidx = y+cols[i];
            if(xidx >= 0 && yidx>=0 && xidx<n && yidx<m) {
                // valid position
                if(grid[xidx][yidx]==1) {
                    grid[xidx][yidx] = 2;
                    q.push({time+1, {xidx, yidx}});
                }
            }
        }
        q.pop();
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return mx;
}

