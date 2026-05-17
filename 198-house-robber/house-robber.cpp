class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);

        if (n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i = 2; i<n ;i++ ){
            dp[i] = max(dp[i-2] , dp[i-1] - nums[i-1]) + nums[i];
        }

        return(max(dp[n-1],dp[n-2]));
    }
};