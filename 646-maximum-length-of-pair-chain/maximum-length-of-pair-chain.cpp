class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),compare);
        vector<int> dp(n,1);
        int mx = 1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(arr[j][1]<arr[i][0]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            mx = max(mx,dp[i]);
        }

        return mx;
    }
};