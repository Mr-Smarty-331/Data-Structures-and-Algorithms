class Solution {
    // since theres no definitive sliding window method 
    // we'll use prefix map
public:
    // implement longest subarray lenth where sum is 0;
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;

        for(int i = 0;i<n;i++) if (arr[i] == 0) arr[i] = -1;

        unordered_map<int,int> pre;
        int mx = 0;

        // finding longest subarray with sum 0
        int cur = 0;
        // pre[0]=-1;
        for(int i = 0;i<n;i++){
            cur+=arr[i];
            if(cur == 0) mx = i+1;
            else if(pre.find(cur)!=pre.end()){
                mx = max(mx,i-pre[cur]);
            }
            else pre[cur] = i;
        }

        return mx;
    }
};