class Solution {
    int count = 0;
    bool isPalin(string &str,int st,int e){
        // int n = e-st+1;
        for(int i = st;i<=e;i++){
            if(str[i]!=str[e-i+st]) return false;
        }
        return true;
    }
    
    // generating the palindromic possible substrings
    void gen(int start,string &s,vector<string>& cur,vector<vector<string>>& ans){
        int n = s.size();
        if (start == n) {ans.push_back(cur);return;}

        for(int i = start;i<n;i++){
            if(isPalin(s,start,i)){
                cur.push_back(s.substr(start,i-start+1));
                gen(i+1,s,cur,ans);
                cur.pop_back();
            }
        }
    }   
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        gen(0,s,cur,ans);
        return ans;
    }
};