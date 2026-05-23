class Solution {
    int recur(int i,int j,string &s,string &p,vector<vector<int>>& dp){
        if (i < 0 && j < 0) return 1;
        if (j < 0) return 0;
        if (i < 0){
            for (int j2 = 0;j2<=j;j2++){
                if(p[j2]!='*') return false;
            }
            return true;
        }

        if (dp[i][j]!=-1) return dp[i][j];

        if (s[i]==p[j] || p[j] == '?'){
            return dp[i][j] = recur(i-1,j-1,s,p,dp);
        }
        else{
            if (p[j] == '*'){
                // * is zero length
                int case1 = recur(i,j-1,s,p,dp);
                // * is of variable length
                int case2 = recur(i-1,j,s,p,dp);

                return dp[i][j] = max(case1,case2);
            }
            return dp[i][j] = 0;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recur(n-1,m-1,s,p,dp);
    }
};