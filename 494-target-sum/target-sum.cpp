class Solution {
    int recur(int ind,int cur,vector<int>& nums) {
        if (ind == 0) {
            if (nums[0] == 0 && cur == 0) return 2;
            if (nums[0]==cur || (cur == -nums[0])) return 1;
            return 0;
        }
        // adding
        int ad = recur(ind-1,cur+nums[ind],nums);
        int sub = recur(ind-1,cur-nums[ind],nums);

        return ad+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // firse wahi pick not pick -- two choice approach
        int n = nums.size();
        if(n==1 && (nums[0]==0 && target==0)) return 2;
        return recur(n-1,target,nums);
    }
};