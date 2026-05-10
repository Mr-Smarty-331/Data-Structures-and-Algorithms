class Solution {
public:
    void dfs(pair<int,int> pos, vector<vector<int>>& vis,vector<vector<char>>& mat){
        int m = vis.size();
        int n = vis[0].size();

        int x = pos.first;
        int y = pos.second;

        vis[x][y] = 1;

        pair<int,int> dir[4] = {{x-1,y},{x,y-1},{x+1,y},{x,y+1}};

        for (auto it : dir) {
            int X = it.first;
            int Y = it.second;

            if ((X>=0&&X<m&&Y>=0&&Y<n) && (!vis[X][Y]) && (mat[X][Y]=='O')) {
                dfs({X,Y}, vis, mat);
            }
        }
    }

    void solve(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<pair<int,int>> bdry;


        for (int i =0 ; i<m ; i++){
            for (int j=0; j<n ; j++){
                if (mat[i][j]=='O' && (i==m-1||j==n-1||i==0||j==0)){
                    bdry.push_back({i,j});
                }
            }
        }

        for (auto it : bdry) {
            dfs({it.first,it.second}, vis,mat);
        }

        for (int i =0 ; i<m ; i++){
            for (int j=0; j<n ; j++){
                if (mat[i][j]=='O' && (!vis[i][j])){
                    mat[i][j]='X';
                }
            }
        }

    }
};