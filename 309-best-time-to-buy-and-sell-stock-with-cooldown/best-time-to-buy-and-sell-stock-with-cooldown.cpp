class Solution {
    // buy : 0 -> cant buy(bought) , 1 -> cant buy(cooldown), 2 -> can buy
    int f(int ind, int buy, vector<int>& cost, vector<vector<int>> &dp){
        int n = cost.size();
        if (ind  == n){
            return 0;
        }

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit = 0;

        if (buy>0){
            int buy_now = (buy==1)? 0: -cost[ind] + f(ind+1,0,cost,dp);
            int buy_later = 0 + f(ind+1,2,cost,dp);

            profit = max(buy_now,buy_later);
        }
        else{
            int sell_now = cost[ind] + f(ind+1,1,cost,dp);
            int sell_later = 0 + f(ind+1,0,cost,dp);

            profit = max(sell_now,sell_later);
        }

        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int> (3,-1));
        return f(0,2,cost,dp);
    }
};