class Solution {
    int viaPrevCoins(vector<int>& coins,int cur_amt,int target,int ind,vector<vector<pair<int,int>>> &dp){
        int n = coins.size();
        if (ind == n){
            if (target == 0) return 1;
            return 0;
        }

        if(dp[target][ind].first==cur_amt) return dp[target][ind].second;

        dp[target][ind].first = cur_amt;

        int pick = 0;
        if (target-coins[ind]>=0) pick = viaPrevCoins(coins,cur_amt,target-coins[ind],ind,dp);

        int notpick = viaPrevCoins(coins,cur_amt,target,ind+1,dp);

        return dp[target][ind].second = pick+notpick;
    }
public:
    vector<int> findCoins(vector<int>& numWays){
        int n = numWays.size();
        vector<int> coins;
        vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(n,{-1,-1}));

        for(int amt = 1;amt<=n;amt++){
            int ways = numWays[amt-1];

            int prevWays = (viaPrevCoins(coins,amt,amt,0,dp));
            if (prevWays == ways) continue;

            if (prevWays!=ways-1 || prevWays>ways) {
                coins.clear();
                break;
            }
            coins.push_back(amt);
        }

        return coins;
    }
};