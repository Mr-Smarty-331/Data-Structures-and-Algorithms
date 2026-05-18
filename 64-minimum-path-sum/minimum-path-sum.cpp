class Solution {
    // int recur(int i,int j, vector<vector<int>>& dp,vector<vector<int>>& grid){

    //     if (i<0||j<0) return INT_MAX;
    //     if (dp[i][j]!=-1) return dp[i][j];

    //     return dp[i][j] = min(recur(i-1,j,dp,grid),recur(i,j-1,dp,grid)) + grid[i][j];
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int> (n,1));
        dp[0][0] = grid[0][0];

        // return recur(m-1,n-1,dp,grid);//memoization
        for(int j = 1;j<n;j++ ){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        // now tabulation
        for(int i = 1;i<m;i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
            for(int j = 0;j<n;j++ ){
                int up = INT_MAX,left = INT_MAX;

                up = dp[i-1][j];
                if (j>0) left = dp[i][j-1];

                dp[i][j] = min(up,left) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};