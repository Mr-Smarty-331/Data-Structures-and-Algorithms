class Solution {
    int recur(int i, int j, string& s1, string & s2, vector<vector<int>>& dp){
        if(i==0||j==0) return 0;

        if (dp[i][j]!=-1) return dp[i][j];

        if (s1[i-1]==s2[j-1]) return dp[i][j] = 1+ recur(i-1,j-1,s1,s2,dp);

        else{
            int moveins1 = recur(i-1,j,s1,s2,dp);
            int moveins2 = recur(i,j-1,s1,s2,dp);

            return dp[i][j] = max(moveins1,moveins2);
        }
    }

public:
    int minInsertions(string s1) {
        string s2 = "";
        int n = s1.size();

        for(int i = n-1;i>=0;i--){
            s2+=s1[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return n - recur(n,n,s1,s2,dp);
    }
};