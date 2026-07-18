class Solution {
public:
    bool canJump(vector<int>& nums) {
        // only problematic element is 0
        // if for all (0's) theres atleat an (element != 0) and its dist from (0) is grester than value of elemtn then true 
        // else false
        // we'll use a mono stack to implement this

        // cant picture it happening

        int n = nums.size();
        int maxReach = 0;
        for(int i = 0;i<n;i++){
            if (i > maxReach) return false;

            maxReach = max( maxReach, i + nums[i] );

            if (maxReach >= n-1) return true;
        }

        return true;
    }
};