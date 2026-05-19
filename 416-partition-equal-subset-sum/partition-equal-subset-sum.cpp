class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum&1) return false;

        int target = sum/2;

        vector<int> dp(target+1,false);

        if(target >= nums[0]) {dp[nums[0]] = true;}

        for(int i= 1;i<n;i++){ 
            dp[0] = true;
            vector<int> cur(target+1,false);
            cur[0] = true;

            for(int j = 0;j<=target;j++){
                bool nottake = dp[j];

                bool take = false;
                if(j>=nums[i]) take = dp[j - nums[i]];

                cur[j] = take||nottake;
            }
            dp = cur;
        }

        return dp[target];
    }
};