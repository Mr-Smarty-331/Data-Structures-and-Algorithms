class Solution {
    int recur(int i,int j,string &s1, string &s2, vector<vector<int>>&dp){
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        //dp is 1 indexed
        if(s1[i-1]==s2[j-1]){
            return dp[i][j] = 1 + recur(i-1,j-1,s1,s2,dp);
        }
        
        else {
            return dp[i][j] = max(recur(i-1,j,s1,s2,dp),recur(i,j-1,s1,s2,dp));
        }
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return recur(n,m,s1,s2,dp);
    }
};