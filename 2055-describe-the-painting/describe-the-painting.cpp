class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();

        map<int, long long> mp;

        for(auto it : segments){
            int start = it[0];
            int end = it[1];
            int val = it[2];

            mp[start]+=val;
            mp[end]-=val;
        }

        vector<vector<long long>> ans;

        long long cur_sum = 0;
        int prev_pos = -1;

        for(auto [cur_pos,change] : mp){
            if(prev_pos!=-1 && cur_sum>0){
                ans.push_back({prev_pos,cur_pos,cur_sum});
            }

            prev_pos = cur_pos;
            cur_sum += change;
        }

        return ans;
    }
};