class Solution {
public:
    int maxProfit(vector<int>& cost) {
        int mn = cost[0];
        int profit = 0;

        for(int i = 1;i<cost.size();i++){
            int cur = cost[i] - mn;
            profit = max(profit,cur);
            mn = min(mn,cost[i]);
        }
        return profit;
    }
};