class Solution {
    int recur(int lvl,int ind,vector<vector<int>>& dp,vector<vector<int>>& triangle){
        if (lvl == 0) return dp[0][0] = triangle[0][0];
        
        if (dp[lvl][ind] != -1) return dp[lvl][ind];

        int mini = INT_MAX;
        // just above the last ind
        if (ind < dp[lvl-1].size()){mini = recur(lvl-1,ind,dp,triangle);}
        // diagonally left to last index
        if(ind-1>=0){mini = min(mini,recur(lvl-1,ind-1,dp,triangle));}
        cout<<mini<<endl;
        return dp[lvl][ind] = mini + triangle[lvl][ind];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        int m = triangle[n-1].size();

        for(int i = 0;i<n;i++) {
            dp[i].resize(i+1,-1);
        }

        int mini = INT_MAX;

        for(int i = 0;i<m;i++ ){
            mini = min(mini,recur(n-1,i,dp,triangle));
        }

        return mini;
    }
};