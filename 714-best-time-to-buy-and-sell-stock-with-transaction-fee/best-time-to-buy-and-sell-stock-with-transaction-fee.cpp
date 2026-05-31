class Solution {
    // we'll pay transacn fee while buying itself
    // to avoid cases of unpaid trnxn fee of bought but not sold due to out of bound
    int f(int ind,int buy,vector<int>& cost, int fee,vector<vector<int>>& dp){
        int n = cost.size();
        if (ind == n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit = 0;

        if (buy) {
            int buy_now = -(cost[ind] + fee) + f(ind+1,0,cost,fee,dp);
            int buy_later = 0 + f(ind+1,1,cost,fee,dp);

            profit = max(buy_now,buy_later);
        }
        else{
            int sell_now = (cost[ind]) + f(ind+1,1,cost,fee,dp);
            int sell_later = 0 + f(ind+1,0,cost,fee,dp);

            profit = max(sell_now,sell_later);       
        }

        return dp[ind][buy] = profit;
    }

    int tab(vector<int>& cost, int fee){
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // int n = cost.size();
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 1;buy>=0;buy--){
                int profit = 0;
                if (buy) {
                    int buy_now = -(cost[ind] + fee) + dp[ind+1][0];
                    int buy_later = 0 + dp[ind+1][1];

                    profit = max(buy_now,buy_later);
                }
                else{
                    int sell_now = cost[ind] + dp[ind+1][1];
                    int sell_later = 0 + dp[ind+1][0];

                    profit = max(sell_now,sell_later);       
                }

                dp[ind][buy] = profit;                
            }
        }
        return (dp[0][1]);
    }

public:
    int maxProfit(vector<int>& cost, int fee) {
        int n = cost.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return f(0,1,cost,fee,dp);
        return tab(cost,fee);
    }
};