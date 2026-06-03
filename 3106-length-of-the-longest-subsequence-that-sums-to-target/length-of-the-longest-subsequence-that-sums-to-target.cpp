class Solution {
    int solve(int ind, int target,vector<int>& nums,vector<vector<int>>& dp){
        int n = nums.size();
        if (ind == n) {
            if (target == 0) return 0;
            return INT_MIN;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int pick = INT_MIN;
        if (target-nums[ind]>=0){
            int val = solve(ind+1,target-nums[ind],nums,dp);
            pick = (val<0)? INT_MIN: 1+val;
            // cout<<pick<<" ";
        }
        int notpick = solve(ind+1,target,nums,dp);
        return dp[ind][target] = max(pick,notpick);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // we'll use the stdd pick not-pick approach
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        sort(nums.begin(),nums.end());
        int ans = solve(0,target,nums,dp);
        return (ans<0)? -1: ans;
    }
};