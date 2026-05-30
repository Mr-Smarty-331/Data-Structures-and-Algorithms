class Solution {
    int n,m;
    bool b = false;
    void init(vector<vector<int>>& grid){
        m = grid[0].size();
        n = grid.size();
    }
    bool isok(int r,int c,vector<vector<int>>& grid){
        if(r>=n || r<0 || c>=m || c<0) return false;
        if(grid[r][c]==-1) return false;
        return true;
    }

    int path(int i,int j,int p, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int q = i+j-p;
        if (i==0 && j ==0 && p==0) {
            b = true;
            return grid[0][0];
        }

        if ((!isok(i,j,grid)) || (!isok(p,q,grid))){
            return -1;
        }
        
        if (dp[i][j][p]!=-1) return dp[i][j][p];

        int mx = -1e9;
        // finding total cherries of the two robots before this step
        bool r1up = isok(i-1,j,grid);
        
        bool r1left = isok(i,j-1,grid);
        
        bool r2left = isok(p,q-1,grid);
        
        bool r2up = isok(p-1,q,grid);
        
        // r1 up , r2 up
        if (r1up && r2up){
            mx = max(mx,path(i-1,j,p-1,grid,dp));
        }
        // r1 left , r2 up
        if (r1left && r2up){
            mx = max(mx,path(i,j-1,p-1,grid,dp));
        }
        
        // r1 left , r2 left
        if (r1left && r2left){
            mx = max(mx,path(i,j-1,p,grid,dp));
        }
        
        // r1 up , r2 left
        if (r1up && r2left){
            mx = max(mx,path(i-1,j,p,grid,dp));
        }
        if (mx == -1e9) return dp[i][j][p]=-1e9;
        return dp[i][j][p] = (i==p && j==q)? (mx + grid[i][j]) : (mx + grid[i][j] + grid[p][q]);
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        init(grid);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(n,-1)));
        int ans = path(n-1,m-1,n-1,grid,dp);
        return (b)? ans : 0;
    }
};