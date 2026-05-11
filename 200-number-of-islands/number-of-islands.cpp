class Solution {
public:
    struct Node { 
        int x,y;
    };

    void dfs(pair<int,int> pos, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        int x = pos.first;
        int y = pos.second;

        vis[x][y]=1;

        Node dir[4] = {{x,y-1},{x-1,y},{x,y+1},{x+1,y}};

        for (int k=0;k<4;k++){
            int X = dir[k].x;
            int Y = dir[k].y;

            if (X>=0&&X<m&&Y>=0&&Y<n&& (!vis[X][Y]) && (grid[X][Y]=='1')) {
                dfs({X,Y},grid,vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        //number of dfs  = number of islands

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<Node> ones;
        
        int cnt=0;

        for (int i = 0;i<m;i++){
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='1' && (!vis[i][j])){
                    // ones.push_back({i,j});
                    cnt++;
                    dfs({i,j},grid,vis);
                }
            }
        }


        // for (auto it : ones) {
        //     if (!vis[it.x][it.y]){
        //         cnt++;
        //         dfs({it.x,it.y},grid,vis);
        //     }
        // }

        return cnt;
    }
};