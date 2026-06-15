class Solution {
    vector<vector<int>> dp;
    int solve(int i,int j, vector<int>& temp){
        // we can clearly see that the order matters
        // treating this as mcm problem
        if (i > j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k = i;k<=j;k++){
            int coins = temp[i-1]*temp[k]*temp[j+1];
            coins += solve(i,k-1,temp) + solve(k+1,j,temp);

            ans = max(ans,coins);
        }

        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();

        temp.push_back(1);
        temp.insert(temp.end(),nums.begin(),nums.end());
        temp.push_back(1);

        dp.resize(n+1,vector<int>(n+1,-1));

        return solve(1,n,temp);
    }
};