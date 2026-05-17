class Solution {
    // int f(int i,int j,vector<vector<int>>& dp){
    //     int m = dp.size();
    //     int n = dp[0].size();

    //     if (i==m-1 && j==n-1) return 1;
    //     else if (i>=m || j>=n) {
    //         return 0;
    //     }

    //     if (dp[i][j]!= -1) return dp[i][j];

    //     return dp[i][j] = f(i+1,j,dp) + f(i,j+1,dp);
    // }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i = 0;i<m;i++) {
            for(int j =0;j<n;j++) {
                if (i==0 && j==0){continue;}
                else {
                    int left = 0;
                    if (j>=1) left = dp[i][j-1];
                    int up = 0;
                    if (i>=1) up = dp[i-1][j];
                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m-1][n-1];

        // return f(0,0,dp);
    }
};