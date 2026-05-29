class Solution {
    bool bs(vector<vector<int>>& matrix,int target,int i){
        int low = 0;
        int high = matrix[0].size()-1;

        while (low<=high){
            int mid = (high+low)/2;

            int cur = matrix[i][mid];

            if (cur == target) return true;

            else if (cur < target){
                low = mid +1;
            }
            else high = mid -1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // for (int i = 0;i<matrix.size();i++){
        //     if (bs(matrix,target,i)) return true;
        // }

        // return false;
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;

        while(row<n && col>=0){
            int cur = matrix[row][col];
            if (cur == target) return true;

            if (cur > target) col--;
            else row++;
        }

        return false;
    }
};