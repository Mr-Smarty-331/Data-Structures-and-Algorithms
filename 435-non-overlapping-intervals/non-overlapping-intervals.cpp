class Solution {
    static bool compare (vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),compare);
        // sorted them in order of increasing ending times

        int cnt = 1;
        auto prev = intervals[0];

        // if the last one ends begfore the next one starts then we include it in the tasks
        // else just move forward
        for(int i = 1;i<n;i++){
            if(intervals[i][0]>=prev[1]) {
                cnt++;
                prev = intervals[i];
            }
        }

        return n - cnt;
    }
};