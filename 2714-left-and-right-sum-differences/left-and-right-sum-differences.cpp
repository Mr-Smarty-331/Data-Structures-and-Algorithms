class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> left(n);
        for(int i=0;i<n;i++) {
            left[i] = sum;
            sum+=nums[i];
        }

        vector<int> ans(n);

        for(int i = 0;i<n;i++){
            ans[i] = abs(2*left[i]-sum+nums[i]);
        }

        return ans;
    }
};