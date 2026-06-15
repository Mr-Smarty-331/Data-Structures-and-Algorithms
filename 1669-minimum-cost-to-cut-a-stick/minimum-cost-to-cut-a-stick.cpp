class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& cuts){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = 1e9;

        for (int  k = i ; k<=j ; k++){
            int cost = (-cuts[i-1]+cuts[j+1]) + solve(i,k-1,cuts) + solve(k+1,j,cuts);
            mini = min(mini,cost);
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> temp = cuts;
        int s = cuts.size();
        temp.push_back(0);
        temp.push_back(n);
        dp.resize(1+s,vector<int>(s+1,-1));
        sort(temp.begin(),temp.end());
        return solve(1,s,temp);
    }
};