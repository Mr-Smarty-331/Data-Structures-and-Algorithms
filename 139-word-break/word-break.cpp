class Solution {
    bool isPart(string s1, string s2,int i){
        int n1 = s1.size();
        int n2 = s2.size();
        int j1 = i;
        int j2 = 0;
        if (i+n2>n1) return false;
        while(j2<n2&& j1<n1){
            if (s1[j1]!=s2[j2]) return false;
            j1++;
            j2++;
        }
        if (j2 == n2 && j1<=n1) return true;
        return false;
    }

    bool solve(int i,string&s ,vector<string>& wordDict,vector<int>& memo){
        int n = s.size();

        if (i==n) {
            return true;
        }
        // memoization bc we may reach an index again after back tracking and do all teh computations again for it
        if (memo[i]!=-1) return memo[i];

        bool b = false;
        for (string word : wordDict){
            if (isPart(s,word,i)){
                b = solve(i+word.size(),s,wordDict,memo);
                if (b) return memo[i] = 1;
            }
        }
        return memo[i] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        vector<int> memo(n,-1);
        return solve(0,s,wordDict,memo);
    }
};