class Solution {
    int f(int ind, int buy, vector<int>& prices,vector<vector<int>>& dp){
        if (ind == prices.size()){
            return 0;
        }
        
        if (dp[ind][buy]!=-1) return dp[ind][buy];

        int profit = 0;
        
        if (buy){
            int buy_now = -prices[ind] + f(ind+1,0,prices,dp);
            int buy_later = 0 + f(ind+1,1,prices,dp);
            profit = max(buy_now,buy_later);
        }
        else{
            int sell_now = prices[ind] + f(ind+1,1,prices,dp);
            int sell_later = 0 + f(ind+1,0,prices,dp);
            profit = max(sell_now,sell_later);
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // present the soln in terms of indices - 1. index where u can buy or sell &
        // 2. whether u can buy or not on that day
        // if can buy - explore buying and not buying
        // else - explore selling and not selling
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};