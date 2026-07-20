class Solution {
public:
    int jump(vector<int>& nums) {
        // similar to jump game - 1
        // but we'll use 2 vars - maxReach & curReach

        int n = nums.size();
        if(n == 1) return 0;
        int maxReach = 0;
        int curReach = 0;
        int jumps = 0;
        
        for(int i = 0;i<n;i++){
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach>=n-1){
                return ++jumps;
            }
            if(i==curReach){
                jumps++;
                curReach = maxReach;
            }
        }

        return 0;
    }
};