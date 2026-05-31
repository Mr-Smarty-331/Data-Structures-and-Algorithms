class Solution {
    int n,minCost;
    vector<int> free;

    void init(vector<vector<int>>& items){
        n = items.size();
        free.resize(n,0);
        minCost = INT_MAX;
        for(int i = 0;i<n;i++){
            minCost = min(minCost,items[i][1]);
            for(int j = 0;j<n;j++){
                if (i!=j && (items[j][0]%items[i][0] == 0)){
                    free[i]++;
                }
            }
        }
    }

    int func(int ind,int left,vector<vector<int>>& items,vector<vector<int>> &dp){
        // base case
        if(ind == n){
            return (left)/minCost;
        }
        if(dp[ind][left]!=-1) return dp[ind][left];
        int ans = 0;
        int price = items[ind][1];
        
        // buy
        if (left>=price){
            ans = 1 + free[ind] + func(ind+1,left-price,items,dp);
        }

        // dont buy
        ans = max(ans,func(ind+1,left,items,dp));
        return dp[ind][left] = ans;
    }

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        init(items);
        vector<vector<int>> dp(n,vector<int>(budget+1,-1));
        return func(0,budget,items,dp);
    }
};
