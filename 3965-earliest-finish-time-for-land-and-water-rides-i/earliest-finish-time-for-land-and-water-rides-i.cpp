class Solution {
    // int solve(int ind,int land_time)
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        //try out all combos
        int n1 = ls.size();
        int n2 = ws.size();
        int time = INT_MAX;
        for(int i = 0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int land = ls[i]+ld[i];
                int water = ws[j]+wd[j];

                int land_water = max(land,ws[j]) + wd[j];
                time = min(time,land_water);

                int water_land = max(water,ls[i]) + ld[i];
                time = min(time,water_land);

            }
        }

        return time;
    }
};