class Solution {
    bool divides(int n1,int n2){
        if ((n1%n2 == 0)||(n2%n1==0)) return true;
        return false;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n);
        vector<int> hash(n);
        int last = 0;

        for(int i = 0;i<n;i++){
            hash[i] = i;
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(divides(nums[i],nums[j]) && dp[i] < dp[j]+1){
                    dp[i] = dp[j] +1;
                    hash[i] = j;
                }
                if (dp[last]<dp[i]) last = i;
            }
        }
        int ind = last;
        vector<int> ans;
        while(true){
            ans.push_back(nums[last]);
            if (last == hash[last]) break;
            last = hash[last];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};