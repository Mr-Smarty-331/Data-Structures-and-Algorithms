class Solution {
public:
    void helper(int i,vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums) {
        if (i>=nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        helper(i+1,ans,curr,nums);
        curr.pop_back();
        helper(i+1,ans,curr,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,ans,curr,nums);
        return ans;
    }
};