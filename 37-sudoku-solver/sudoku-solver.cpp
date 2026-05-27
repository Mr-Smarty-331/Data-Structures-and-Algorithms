class Solution {
    bool isok(int n, vector<vector<char>>& board,int x,int y){
        int lx,ly;
        if (x<3) lx = 0;
        else if (x<6) lx = 3;
        else lx = 6;
        if (y<3) ly = 0;
        else if (y<6) ly = 3;
        else ly = 6;

        for (int i = lx;i<lx+3;i++){
            for(int j= ly;j<ly+3;j++){
                if((board[i][j]-'0')==n) return false;
            }
        }

        for(int i = 0;i<9;i++){
            if (i==x) continue;
            if (board[i][y]-'0' == n) return false;
        }

        for(int i = 0;i<9;i++){
            if (i==y) continue;
            if (board[x][i]-'0' == n) return false;
        }       

        return true;
    }

    bool solve(int x,int y,vector<vector<char>>& board){
        if (x==9) return true;
        if (y==9) {
            if (solve(x+1,0,board)) return true;
            return false;
        }

        if (board[x][y]!='.') {
            if (solve(x,y+1,board)) return true;
            return false;
        }

        for (int i = 1;i<=9;i++){
            if(isok(i,board,x,y)){
                board[x][y] = '0'+i;
                if (solve(x,y+1,board)) return true;
                board[x][y] = '.';
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};