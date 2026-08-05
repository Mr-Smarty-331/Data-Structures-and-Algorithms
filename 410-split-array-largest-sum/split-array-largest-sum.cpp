class Solution {
    bool check(int sum, vector<int>& nums,int k) {
        int cur = 0;
        int n = nums.size();
        int count = 1;
        for(int i = 0;i<n;i++) {
            if((cur+nums[i])>sum) {
                cur = 0;
                count ++;
            }
            cur+=nums[i];
        }
        return (count <= k);
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int mx_el = INT_MIN;
        for(int x : nums){
            sum+=x;
            mx_el = max(mx_el, x);
        }

        int low = mx_el;
        int high = sum;

        int mid;
        int ans;

        while(low <= high) {
            mid = low + (-low + high)/2;

            if (check(mid,nums,k)) {
                ans = mid;
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};