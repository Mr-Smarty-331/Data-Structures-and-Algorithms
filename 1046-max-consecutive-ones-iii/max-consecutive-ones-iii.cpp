class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,r=0;
        int mx=0,z=0;

        while(r<n){
            if (arr[r]==0) z++;
            if(z>k){
                if (arr[l]==0) z--;
                l++;
            }
            if (z<=k) mx=max(mx,r-l+1);
            r++;
        }
        return mx;

    }
};