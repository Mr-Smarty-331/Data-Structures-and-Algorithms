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

        for(int i=0;i<m;i++) {
            if (grid[i][0]==1 && (!vis[i][0])) {
                dfs({i,0},vis,grid);
            }
        }
        for(int i=0;i<m;i++) {
            if (grid[i][n-1]==1 && (!vis[i][n-1])) {
                dfs({i,n-1},vis,grid);
            }
        }
        for(int i=0;i<n;i++) {
            if (grid[0][i]==1 && (!vis[0][i])) {
                dfs({0,i},vis,grid);
            }
        }
        for(int i=0;i<n;i++) {
            if (grid[m-1][i]==1 && (!vis[m-1][i])) {
                dfs({m-1,i},vis,grid);
            }
        }

        int total=0;
        int cnt=0;

        for (int i =0;i<m;i++){
            for (int j=0;j<n;j++) {
                if (vis[i][j]) cnt++;
                if (grid[i][j]) total++;
            }
        }

        return total-cnt;

    }
};