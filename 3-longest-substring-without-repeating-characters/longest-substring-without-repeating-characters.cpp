class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> arr(128,-1);
        int l=0;
        int r;
        int mx=0;
        for (r=0;r<n;r++){
            char ch=s[r];
            if (arr[ch]!=-1){
                l=max(l,arr[ch]+1);
            }
            mx=max(mx,r-l+1);
            arr[ch]=r;
        }
        return mx;
    }
};