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
        // vector<vector<int>> dp(m,vector<int>(n,0));
        // dp[0][0] = 1;

        // for(int i = 0;i<m;i++) {
        //     for(int j =0;j<n;j++) {
        //         if (i==0 && j==0){continue;}
        //         else {
        //             int left = 0;
        //             if (j>=1) left = dp[i][j-1];
        //             int up = 0;
        //             if (i>=1) up = dp[i-1][j];
        //             dp[i][j] = left + up;
                    
        //             // cout<<dp[i][j]<<" ";
        //         }

        //     }
        //     // cout<<endl;
        // }
        // ____________________________
        // space optimization - we'll use a dummy dp(n) vector bc we only need one row for processing
        // (we are processing one row at a time only)
        // ____________________________
        vector<int> dp(n,1); // accessing the top nbr
        vector<int> cur(n,1); //for accessing the left nbr

        for(int j = 1;j<m;j++) {
            for(int i =0;i<n;i++ ){
                int up = dp[i];
                int left = 0;
                if (i>0) left = cur[i-1];
                cur[i] = up+left;
                dp = cur;
            }
        }
        return dp[n-1];

        // return f(0,0,dp);
    }
};