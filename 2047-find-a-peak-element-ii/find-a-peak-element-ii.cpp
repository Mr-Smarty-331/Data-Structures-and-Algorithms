class Solution {
    int m,n;
    void init(vector<vector<int>>& mat){
        n = mat.size();
        m = mat[0].size();
    }

    int colMax(int i,vector<vector<int>>& mat){
        int mx = 0;
        int ind = 0;
        for(int j = 0;j<n;j++){
            if (mat[j][i]>mx){
                mx = mat[j][i];
                ind = j;
            }
        }

        return ind;
    }

    int check(int r, int c,vector<vector<int>>& mat){
        // -1 = this cell is peak
        // 0 -> left
        // 1 -> right
        int bdr = -1;//bdry dirn = -1

        int left = (c==0)? bdr : mat[r][c-1];
        int right = (c==m-1)? bdr : mat[r][c+1];
        int cur = mat[r][c];
        if (cur > left && cur > right) return -1;
        else return (left>right)? 0:1;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // we need to find just one peak
        // so by eliminating entire columns if its max isnt a peak
        // we are assured to head towards at least one peak direction

        // bs on columns of the matrix
        init(mat);

        int low = 0;
        int high = m-1;

        while (low<=high){
            int mid = (low+high)/2;

            int row = colMax(mid,mat);
            
            int ver = check(row,mid,mat);
            if (ver == -1) return vector<int> {row,mid};

            else if (ver == 0) {
                high = mid-1;
            }
            else low = mid+1;
        }
        return vector<int> {};
    }

};