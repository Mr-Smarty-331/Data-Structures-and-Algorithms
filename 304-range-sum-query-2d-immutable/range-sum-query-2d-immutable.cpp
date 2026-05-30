class NumMatrix {
private:
    int n,m;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if (j == 0) {dp[i][j] = matrix[i][0];continue;}
                dp[i][j] += matrix[i][j] + dp[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;

        for(int r = row1;r<=row2;r++){
            int sub = 0;
            if (col1!=0) sub = dp[r][col1-1];
            ans += dp[r][col2] - sub;
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */