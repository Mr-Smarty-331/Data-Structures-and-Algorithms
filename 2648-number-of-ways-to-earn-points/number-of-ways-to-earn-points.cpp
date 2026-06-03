class Solution {
    int M = 1e9+7;
    int solve(int ind,int target,vector<vector<int>>& types,vector<vector<int>> &dp){
        int n = types.size();
        if (ind == n){
            if(target == 0) return 1;
            return 0;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int count = types[ind][0];
        int score = types[ind][1];
        
        int nways = 0;
        
        for(int i = 0;i<=count;i++){
            if (target - i*score < 0) break;
            nways += solve(ind+1,target-i*score,types,dp);
            nways%=M;
        }

        return dp[ind][target] = (nways)%M;
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,target,types,dp);
    }
};