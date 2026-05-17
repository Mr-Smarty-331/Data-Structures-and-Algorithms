class Solution {
    int f(int i,int j,vector<vector<int>>& dp){
        int m = dp.size();
        int n = dp[0].size();
        
        if (i==m-1 && j==n-1) return 1;
        else if (i>=m || j>=n) {
            return 0;
        }

        if (dp[i][j]!= -1) return dp[i][j];

        return dp[i][j] = f(i+1,j,dp) + f(i,j+1,dp);
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return f(0,0,dp);
    }
};