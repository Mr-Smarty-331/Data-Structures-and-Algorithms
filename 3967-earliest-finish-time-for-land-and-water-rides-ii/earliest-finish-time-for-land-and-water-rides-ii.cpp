class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size();
        int m = ws.size();
        // A. finding best result if we did land first then moving onto water

        int minTime_l_w = INT_MAX;
        for(int i = 0;i<n;i++){
            if(ls[i]+ld[i]<minTime_l_w) minTime_l_w = ls[i]+ld[i];
        }
        //choosing the best water event
        int res1 = INT_MAX;
        for(int j = 0;j<m;j++){
            res1 = min(res1,max(minTime_l_w,ws[j]) + wd[j]);
        }

        int minTime_w_l = INT_MAX;
        for(int i = 0;i<m;i++){
            if(ws[i]+wd[i]<minTime_w_l) minTime_w_l = ws[i]+wd[i];
        }
        //choosing the best water event
        int res2 = INT_MAX;
        for(int j = 0;j<n;j++){
            res2 = min(res2,max(minTime_w_l,ls[j]) + ld[j]);
        }
        return min(res1,res2);
    }
};