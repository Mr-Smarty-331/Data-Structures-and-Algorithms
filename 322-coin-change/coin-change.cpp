class Solution {
    int f(int ind,int tar,vector<int>& coins,vector<vector<int>>& dp){
        if (ind == 0) {

            if (tar%coins[ind]==0) return tar/coins[ind];
            dp[ind][tar] = 1e9;
        }

        if(dp[ind][tar]!=-1) return dp[ind][tar];

        int take = INT_MAX;
        if (tar>=coins[ind]) take = 1+f(ind,tar-coins[ind],coins,dp);

        //we'll start from the back of the coins array
        int nottake = f(ind-1,tar,coins,dp);

        return dp[ind][tar] = min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // int ans = f(n-1,amount,coins,dp);

        for(int t = 0;t<amount+1;t++ ){
            if(t%coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }

        for(int i = 1;i<n;i++){
            for(int j = 0;j<=amount;j++){
                int take = INT_MAX;
                if (j>=coins[i]) take = 1+dp[i][j-coins[i]];

                //we'll start from the back of the coins array
                int nottake = dp[i-1][j];

                dp[i][j] = min(take,nottake);                
            }
        }

        int ans = dp[n-1][amount];
        return ans>=1e9? -1:ans;
    }
};