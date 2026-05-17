class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n,0);
        // dp[0] = 1;
        if (grid[m-1][n-1]==1) return 0;

        for(int i = 0;i<m;i++) {
            vector<int> cur(n);
            for(int j = 0;j<n;j++){
                if (grid[i][j]==1) {cur[j] = 0;continue;}
                if (i == 0 && j==0 ){ cur[0] = 1;continue;}
                int up = dp[j];
                int left = 0;
                if (j>0) left = cur[j-1];

                cur[j] = left + up;//left and up
            }
            dp = cur;
        }

        return dp[n-1];
    }
};