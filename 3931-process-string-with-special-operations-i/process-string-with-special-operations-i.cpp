class Solution {
public:
    string processStr(string& s) {
        string ans = "";

        for(char ch : s){
            int c = ch-'a';
            if (c>=0 && c<26) ans += ch;

            else if (ch == '*' && (!ans.empty())) ans.pop_back();

            else if (ch == '#') ans+=ans;

            else reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};