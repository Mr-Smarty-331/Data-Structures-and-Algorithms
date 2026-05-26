class Solution {
    vector<vector<int>> vis;
    bool check(vector<vector<char>>& grid, string & word,int x,int y,int i,int gen,vector<vector<int>>& vis){
        if (i==word.size()) return true;
        vis[x][y] = gen;
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {x-1,x,x+1,x};
        int dy[4] = {y,y-1,y,y+1};
        bool b = false;
        for(int j = 0;j<4;j++){
            int X = dx[j];
            int Y = dy[j];

            if ((X<n&&X>=0&&Y<m&&Y>=0)&&(grid[X][Y]==word[i])&&(vis[X][Y]!=gen)){
                b= check(grid,word,X,Y,i+1,gen,vis);
                if (b) return b;
            }
        }
        vis[x][y] = gen-1;
        return false;
    }

public:
    bool exist(vector<vector<char>>& grid, string word) {
        // stack<pair<int,int>> st;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        bool b = false;
        int genc = 0;
        for(int x =0;x<n;x++){
            for(int y = 0;y<m;y++){
                if (grid[x][y]==word[0]){
                    genc++;
                    b = check(grid,word,x,y,1,genc,vis);
                    if (b) return true;
                }
            }
        }
        return b;
    }
};