class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for (auto x : nums) {
            mp[x]++;
        }

        priority_queue<pair<int,int>> pq; //max heap - max freq first;

        for(auto [num,freq] : mp){
            pq.push({freq,num});
        }
        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};