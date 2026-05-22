class Solution {
    int recur(int  i ,int j,string& s1, string& s2, vector<vector<int>>& dp){
        if (i==0 || j==0) return 0;

        if(dp[i][j]!= -1) return dp[i][j];
        //match
        if (s1[i-1]==s2[j-1]){
            return dp[i][j] = 1+ recur(i-1,j-1,s1,s2,dp);
        }

        else{
            int up = recur(i-1,j,s1,s2,dp);
            int left = recur(i,j-1,s1,s2,dp);

            return dp[i][j] = max(up,left);
        }
    }
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = "";
        int n = s1.size();

        for (char ch : s1){
            s2 = ch+s2;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return recur(n,n,s1,s2,dp);

    }
};