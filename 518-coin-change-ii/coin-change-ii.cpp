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
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return recur(n-1,amount,coins,dp);
    }
};