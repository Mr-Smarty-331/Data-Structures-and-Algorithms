class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,pair<int,int>> hash;
        int n = nums.size();
        int lim = n/3;

        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(hash[nums[i]].second) continue;
            hash[nums[i]].first++;
            if(hash[nums[i]].first>lim) {
                ans.push_back(nums[i]);
                hash[nums[i]].second = 1;
            }
        }

        return ans;
    }
};