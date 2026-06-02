class Solution {
    int solve(int ind, int lt, string&s,vector<vector<int>>& dp){
        int n = s.length();
        if (ind == n){
            if (lt) return 1;
            return 0;
        }
        
        if (dp[ind][lt]!=-1) return dp[ind][lt];

        int result = 0;
        if (lt) {
            if (s[ind] == '0') return 0;
            int take = solve(ind+1,1,s,dp);
            int nottake = solve(ind+1,0,s,dp);

            result = take+nottake;
        }
        else {
            int l = s[ind-1]-'0';
            int cur = s[ind] - '0';
            int total = l*10+cur;
            if((total<=26 && total>0)) {
                result = solve(ind+1,1,s,dp);
            }
        }

        return dp[ind][lt] = result;

    }
public:
    int numDecodings(string s) {
        int n = s.size();

        if (s[0]=='0') return 0;
        for(int j = 0;j<n;j++){
            if (s[j]=='0' && (s[j-1]-'0' > 2 || s[j-1] == '0')) return 0;
        }

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,s,dp);
    }
};