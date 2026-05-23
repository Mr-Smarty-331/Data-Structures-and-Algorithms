class Solution {
    int f(int i,int j,string&s1,string&s2,vector<vector<int>>& dp){
        if(i < 0){
            return j+1; // remaining insertions
        }
        if(j < 0){
            return i+1; // remaining deletions
        }

        if (dp[i][j]!=-1) return dp[i][j];

        if (s1[i]==s2[j]) {
            return dp[i][j] = f(i-1,j-1,s1,s2,dp);
        }

        int del = 1 + f(i-1,j,s1,s2,dp);
        int ins = 1 + f(i,j-1,s1,s2,dp);
        int rep = 1 + f(i-1,j-1,s1,s2,dp);

        return dp[i][j] = min(del,min(ins,rep));
    }
public:
    int minDistance(string s1, string s2) {
        // do the actions on the string 1 and move via indices aptly

        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return f(n-1,m-1,s1,s2,dp);
    }
};