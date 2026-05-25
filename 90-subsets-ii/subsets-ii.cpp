class Solution {
    void helper(vector<int>& nums,int start,vector<int>& cur,vector<vector<int>>& ans){
        // if (start == 0) ans.push_back(cur);
        ans.push_back(cur);

        if (start == nums.size()) {
            return;
        }

        // if its the same as last one - we'll take it if its the first element of current recursion as stated by the if statement

        for (int i = start; i<nums.size(); i++){
            if (i>0 && (nums[i]==nums[i-1]) && (i!=start)) continue;

            cur.push_back(nums[i]);
            helper(nums,i+1,cur,ans);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        helper(nums,0,cur,ans);
        return ans;
    }
};