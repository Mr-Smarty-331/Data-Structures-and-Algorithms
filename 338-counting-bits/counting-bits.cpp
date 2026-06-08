class Solution {
    int solve(int i, vector<int> &dp){
        if (dp[i]!=-1) return dp[i];
        if ( i == 0 || i == 1) return dp[i] = i;
        int num = i;
        num = num&(num-1);
        return dp[i] = 1 + solve(num,dp); 
    }
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,-1);
        for(int i = n;i>-1;i--) {
            solve(i,dp);
        }
        return dp;
    }
};