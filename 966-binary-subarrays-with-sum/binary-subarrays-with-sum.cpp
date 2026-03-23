class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        map<int,int> mp;
        int count=0;

        mp[0]=1;
        int sum=0;
        if (nums.size()==1&&nums[0]!=k) return 0;
        for(int x:nums) {
            sum+=x;
            if(mp.contains(sum-k)) {
                count+=mp[sum-k];
            }
            mp[sum]++;
        }

        return count;
    }
};