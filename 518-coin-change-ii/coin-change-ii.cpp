class Solution {
    int recur (int ind,int sum,vector<int>& coins,vector<vector<int>>& dp){
        if (ind == 0) {
            if (sum == 0) return 1;
            if (sum%coins[0]==0) return 1;
            return 0;
        }
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];

        int take = 0;
        if (coins[ind] <= sum) take = recur(ind,sum-coins[ind],coins,dp);

        int nottake = recur(ind-1,sum,coins,dp);

        return dp[ind][sum] = nottake+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        // vector dp
        // recur fn from top(ans to base)
        int n = coins.size();
        vector<vector<unsigned int>> dp(n,vector<unsigned int>(amount+1,0));
        dp[0][0] = 1;
        for(int j = 1;j<=amount;j++){
            if (j%coins[0] == 0) dp[0][j] =1;
        }

        for(int ind =1;ind<n;ind++) {
            for(int sum = 0;sum<=amount;sum++) {
                unsigned int take = 0;

                if (coins[ind] <= sum) take = dp[ind][sum-coins[ind]];

                unsigned int nottake = dp[ind-1][sum];

                dp[ind][sum] = nottake + take;
            }
        }

        return int (dp[n-1][amount]);
    }
};