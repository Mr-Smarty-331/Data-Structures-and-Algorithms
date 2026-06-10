class Solution {
    int n,m;
    vector<vector<int>> dp;

    int solve(int r, int c,vector<vector<int>>& grid){

        if (r == n-1 && c == m-1){
            int req = 1 - grid[r][c];
            if(req<=0) req = 1;
            return req;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int right = 1e5;
        if (c+1 < m) right = solve(r,c+1,grid);

        int down = 1e5;
        if (r+1 < n) down = solve(r+1,c,grid);
        int req = min(down,right) - grid[r][c];
        return dp[r][c] = (req<=0)? 1: req;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,grid);
    }
};