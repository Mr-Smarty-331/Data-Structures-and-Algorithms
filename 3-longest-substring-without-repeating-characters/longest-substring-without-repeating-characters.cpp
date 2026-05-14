class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int s = str.size();

        vector<int> recent(128,-1);

        int l = 0;
        int mx = 0;
        for (int r = 0;r<s; r++) {
            char ch = str[r];
            
            if (recent[ch]!=-1){
                l = max(l,recent[ch]+1);
            }

            recent[ch] = r;
            mx = max(mx,r-l+1);
        }
        return mx;
    }
};