class Solution {
    int f(int ind, int buy, int txn, vector<int>& cost, vector<vector<vector<int>>>& dp){
        // we can have another state that tells us how many payments we've made till now 
        // if its 2 we return if we,ve no unsold stock
        // if we,ve unsold stock we return when we sell it(normal case)
        int n = cost.size();
        if ((txn==2 && buy) || ind == n) {
            return 0;
        }
        if (dp[ind][buy][txn] !=-1) return dp[ind][buy][txn];
        int profit = 0;
        if (buy) {
            // we may buy or we may not
            int buy_now = -cost[ind] + f(ind +1, 0, txn+1,cost,dp);
            int buy_later = 0 + f(ind+1,1,txn,cost,dp);
            profit = max(buy_now,buy_later);
        }
        else {
            int sell_now = cost[ind] + f (ind+1, 1, txn,cost,dp);
            int sell_later = f (ind+1, 0, txn,cost,dp);
            profit = max(sell_now,sell_later);
        }
        return dp[ind][buy][txn] = profit;
    }
public:
    int maxProfit(vector<int>& cost) {
        int n = cost.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,0,cost,dp);
    }
};