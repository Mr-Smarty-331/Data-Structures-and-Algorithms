class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // ts ain't dp dawg
        // bfs traversal
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<vector<int>> q; // r,c,step,removals

        q.push({0,0,0,0});

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int r = t[0],c = t[1],step=t[2],rem = t[3];

            // if not a valid coord remove and skip path
            if (r<0 || r>=n || c<0 || c>=m) continue;
            if (rem > k) continue;

            if (r==n-1 && c==m-1) return step;

            // updating the removals
            if (grid[r][c]==1) rem++;

            if ((vis[r][c]!=-1) && vis[r][c]<=rem) continue; 
            if ((vis[r][c]==-1) || vis[r][c]>rem) vis[r][c] = rem;

            // up 
            q.push({r-1,c,step+1,rem});
            // left
            q.push({r,c-1,step+1,rem});
            // down
            q.push({r+1,c,step+1,rem});
            // right
            q.push({r,c+1,step+1,rem});
        }

        return -1;
    }
};