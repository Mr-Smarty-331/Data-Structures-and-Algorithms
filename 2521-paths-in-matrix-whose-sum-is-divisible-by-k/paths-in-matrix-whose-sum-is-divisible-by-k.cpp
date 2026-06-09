class Solution {
    int n,m;
    vector<vector<vector<int>>> dp;
    int M = 1e9+7;
    int solve(int sum, int r, int c, vector<vector<int>>& grid,int k){
        sum = (sum+grid[r][c])%k;
        if (r == n-1 && c == m-1) {
            if ((sum)%k == 0) return 1;
            return 0;
        }
        if (dp[sum][r][c]!=-1) return dp[sum][r][c];
        
        int right = 0;
        if(c+1<m) right = solve(sum,r,c+1,grid,k);
        int down = 0;
        if(r+1<n) down = solve(sum,r+1,c,grid,k);

        return dp[sum][r][c] = (right+down)%M;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(k,vector<vector<int>>(n+1,vector<int>(1+m,-1)));

        int ans = solve(0,0,0,grid,k);

        return ans;
    }
};