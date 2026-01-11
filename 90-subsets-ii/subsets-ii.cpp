class Solution {
public:
    void func(vector<int>& nums,vector<vector<int>>& ans,int ind,vector<int> curr){
        ans.push_back(curr);
        if (ind==nums.size()){
            return;
        }
        // ans.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            // ans.push_back(curr);
            if (i>ind&&nums[i]==nums[i-1]) continue;
            // ans.push_back(curr);
            curr.push_back(nums[i]);
            func(nums,ans,i+1,curr);
            // ans.push_back(curr);
            curr.pop_back();
            // ans.push_back(curr);
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        func(nums,ans,0,{});
        return ans;
    }
};