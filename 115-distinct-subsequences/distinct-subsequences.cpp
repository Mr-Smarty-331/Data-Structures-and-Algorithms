class Solution {
    map<pair<int,int>,int> memo;
    int f(int i,int j,string& s1,string& s2,string str,vector<vector<int>>& dp){
        if (i<0 || j<0){
            if (str == s2) return 1;
            return 0;
        }

        // if (memo.count({i,j})) return memo[{i,j}];
        if (dp[i][j]!=-1) return dp[i][j];

        //pick 
        int pick = 0;
        if (s1[i]==s2[j]){
            pick = f(i-1,j-1,s1,s2,s1[i] + str,dp) ;
        }
        int notpick = f(i-1,j,s1,s2,str,dp);
        return dp[i][j] = pick + notpick;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return f(n-1,m-1,s,t,"",dp);
    }
};