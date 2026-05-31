class Solution {
    int f(int ind, int txn, vector<int>& cost, vector<vector<int>>& dp, int k){
        int n = cost.size();
        if(txn == 2*k || ind == n) return 0;

        if (dp[ind][txn]!=-1) return dp[ind][txn];
        
        bool buy = !(txn&1);// starting with 0 -> eventh txn is to buy, oddth is to sell

        int profit = 0;
        if (buy) {
            int buy_now = -cost[ind] + f(ind+1,txn+1,cost,dp,k);
            int buy_later = 0 + f(ind+1,txn,cost,dp,k);

            profit = max(buy_now,buy_later);
        }

        else{
            int sell_now = cost[ind] + f(ind+1,txn+1,cost,dp,k);
            int sell_later = 0 + f(ind+1,txn,cost,dp,k);

            profit = max(sell_now,sell_later);
        }

        return dp[ind][txn] = profit;
    }
public:
    int maxProfit(int k, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return f(0,0,cost,dp,k);
    }
};