class Solution {
    void dfs(pair<int,int> pos,vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int x = pos.first;
        int y = pos.second;

        int m=grid.size();
        int n=grid[0].size();

        vis[x][y] = 1;

        pair<int,int> dir[4] = {{x-1,y},{x+1,y}, {x,y-1}, {x,y+1}};

        for (auto it : dir) {
            int X = it.first;
            int Y = it.second;

            if ((X>=0&&X<m&&Y>=0&&Y<n)&&(!vis[X][Y])&&(grid[X][Y]==1)){
                dfs({X,Y},vis,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int total = 0;

        for(int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==1) total++;

                if (grid[i][j]==1 && (i==0||i==m-1||j==0||j==n-1)&& (!vis[i][j])) {
                    dfs({i,j},vis,grid);
                }
            }
        }
        int cnt=0;

        for (auto it : vis){
            for (int p : it) {
                if (p) cnt++;
            }
        }

        return total-cnt;

    }
};