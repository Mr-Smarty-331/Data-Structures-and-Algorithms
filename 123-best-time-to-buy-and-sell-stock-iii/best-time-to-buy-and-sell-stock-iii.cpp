class Solution {
    int f(int ind, int txn, vector<int>& cost, vector<vector<int>>& dp){
        // we can have another state that tells us how many payments we've made till now 
        // if its 2 we return if we,ve no unsold stock
        // if we,ve unsold stock we return when we sell it(normal case)
        int n = cost.size();
        if (txn==4 || ind == n) {
            return 0;
        }

        bool buy = !(txn&1);
        
        if (dp[ind][txn] !=-1) return dp[ind][txn];
        
        int profit = 0;
        if (buy) {
            // we may buy or we may not
            int buy_now = -cost[ind] + f(ind +1, txn+1,cost,dp);
            int buy_later = 0 + f(ind+1,txn,cost,dp);
            profit = max(buy_now,buy_later);
        }
        else {
            int sell_now = cost[ind] + f(ind+1, txn+1,cost,dp);
            int sell_later = f(ind+1, txn,cost,dp);
            profit = max(sell_now,sell_later);
        }
        return dp[ind][txn] = profit;
    }
public:
    int maxProfit(vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(0,0,cost,dp);
    }
};