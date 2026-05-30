class NumMatrix {
private:
    int n,m;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n+1,vector<int>(m+1,0));

        for(int i = 1;i<=n;i++){
            vector<int> cur(m+1,0);
            for(int j = 1;j<=m;j++){
                cur[j] = cur[j-1]+matrix[i-1][j-1];
                dp[i][j] = cur[j] + dp[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        int main = dp[row2][col2];
        int sub1 = 0;
        if (row1>=1) sub1 = dp[row1-1][col2];
        int sub2 = 0;
        if (col1>=1) sub2 = dp[row2][col1-1];
        int add = 0;
        if (row1>=1 && col1>=1) add = dp[row1-1][col1-1];

        return main-sub1-sub2+add;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */