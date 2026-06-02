class Solution {
private:
    bool static compare(string& s,string& t){
        return s.size() < t.size();
    }

    bool check(string& succ,string& pred){
        if (succ.size()!=pred.size()+1) return false;
        int i = 0;
        int j = 0;
        while(i<succ.size()){
            if(j<pred.size() && succ[i]==pred[j]) {i++;j++;continue;}
            i++;
        }

        if (i==succ.size() && j==pred.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();

        vector<int> dp(n,1);

        int mx = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if (check(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i] = dp[j] +1;
                }
            }
            if (mx<dp[i]){
                mx = dp[i];
            }
        }

        return mx;
    }
};