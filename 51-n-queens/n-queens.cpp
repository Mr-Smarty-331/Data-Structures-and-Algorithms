class Solution {
    // check if queen can be placed
    bool canPlace(int x,int y,vector<string> & poss){
        // check vertically and horiz
        int n = poss.size();
        for (int i = 0;i<n;i++){
            if (poss[i][y] == 'Q') return false;
            if (poss[x][i] == 'Q') return false;
        }

        //check diagonal cells only left 2 diagonals
        int r = x;
        int c = y;
        
        while(r>=0 && c>=0){
            if (poss[r][c]=='Q') return false;
            r--;
            c--;
        }
        r = x;
        c = y;
        while(r>=0 && c<n){
            if (poss[r][c]=='Q') return false;
            r--;
            c++;
        }

        return true;
    }

    // fill the board with Queens
    void solve(int row,int n,vector<string> & poss,vector<vector<string>>& ans){
        if(row == n) {ans.push_back(poss);return;}

        for(int i = 0;i<n;i++){
            if (canPlace(row,i,poss)){
                poss[row][i] = 'Q';
                solve(row+1,n,poss,ans);
                poss[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        if (n==2||n==3) return vector<vector<string>> {};
        vector<string> poss(n);
        string s(n,'.');
        for(int i=0;i<n;i++) poss[i] = s;
        vector<vector<string>> ans;
        solve (0,n,poss,ans);
        return ans;
    }
};