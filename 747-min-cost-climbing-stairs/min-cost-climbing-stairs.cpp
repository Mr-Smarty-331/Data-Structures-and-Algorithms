class Solution {
    int recur(int i , vector<int>& cost,vector<int>& dp){
        if (i<=1){
            return cost[i];
        }
        if (dp[i]!=-1) return dp[i];
        int last1 = recur(i-1,cost,dp);
        int last2 = recur(i-2,cost,dp);

        int best = min(last1,last2);
        if (i==cost.size()-1) return min(cost[i]+last2,last1);
        return dp[i] = cost[i]+best;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        if (n==2) return min(cost[1],cost[0]);
        return recur(n-1,cost,dp);
    }
};