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

        // vector<vector<int>> dp(m,vector<int> (n,1));
        // dp[0][0] = grid[0][0];

        // return recur(m-1,n-1,dp,grid);//memoization
        // now space optimization
        
        // for(int j = 1;j<n;j++ ){
        //     dp[0][j] = dp[0][j-1] + grid[0][j];
        // }
        // now tabulation
        vector<int> dp(n,INT_MAX);
        
        for(int i = 0;i<m;i++) {
            // dp[i][0] = grid[i][0] + dp[i-1][0];
            vector<int> cur(n,0);
            for(int j = 0;j<n;j++ ){
                if(i==0&&j==0) {
                    cur[0] = grid[0][0];
                    continue;
                }
                if (j == 0){
                    cur[0] = dp[0]+grid[i][0];
                    continue;
                }

                int up = INT_MAX,left = INT_MAX;

                up = dp[j];
                left = cur[j-1];
                // if (j>0) left = dp[i][j-1];

                cur[j] = min(up,left) + grid[i][j];

            }
            dp = cur;
        }

        return dp[n-1];

    }
};