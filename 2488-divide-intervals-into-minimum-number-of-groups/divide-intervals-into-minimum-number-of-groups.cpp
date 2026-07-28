class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // algo is similar to min platforms - where two overlapping intervals cant be in the same group 
        int n = intervals.size();
        vector<int> start;
        vector<int> end;

        for(int i = 0;i<n;i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i = 0,j = 0;
        int cnt = 0,ans= 0;

        while (i<n && j<n){
            if(start[i]<=end[j]){
                i++;
                cnt++;
                ans=max(ans,cnt);
            }
            else{
                j++;
                cnt--;
            }
        }

        return ans;
    }
};