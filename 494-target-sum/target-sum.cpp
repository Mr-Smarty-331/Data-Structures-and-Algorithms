class Solution {
    int recur(int ind,int cur,vector<int>& nums,vector<vector<int>>& dp,int sum) {
        if (abs(cur) > sum)
            return 0;
        if (ind == 0) {
            if (nums[0] == 0 && cur == 0) return 2;
            if (nums[0]==cur || (cur == -nums[0])) return 1;
            return 0;
        }
        int shift = cur + sum;
        if (dp[ind][shift] != -1) return dp[ind][shift];

        int ad = recur(ind-1,cur+nums[ind],nums,dp,sum);
        int sub = recur(ind-1,cur-nums[ind],nums,dp,sum);

        return dp[ind][shift] = ad+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // firse wahi pick not pick -- two choice approach
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        if (abs(target) > sum) return 0;

        int s = 2*sum+1;
        vector<vector<int>> dp(n,vector<int>(s,-1));

        return recur(n-1,target,nums,dp,sum);
    }
};