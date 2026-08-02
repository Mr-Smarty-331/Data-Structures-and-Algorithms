class Solution {
public:
    int findTheLongestSubstring(string& s) { 
        map<char,int> vow = {{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        int n = s.size();
        int mx_len = 0;

        vector<int> first_seen(32,-2); // to track down when a state is forst seen

        first_seen[0] = -1;

        int mask = 0;
        for(int i = 0;i<n;i++) {
            char ch = s[i];

            if (vow.find(ch)!=vow.end()){
                mask^=(1<<vow[ch]);
            }

            if (first_seen[mask]!=-2) {
                // its been seen before
                mx_len = max(mx_len,i-first_seen[mask]);
            }

            else{
                first_seen[mask] = i;
            }
        }

        return mx_len;
    }
};