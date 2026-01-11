class Solution {
public:
    void func(string& digits,vector<string>& ans, string curr,int ind, const vector<string>& comb){
        if (curr.size()==digits.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<comb[digits[ind]-'0'].size();i++){
            func(digits,ans,curr+comb[digits[ind]-'0'][i],ind+1,comb);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> comb={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr="";
        func(digits,ans,curr,0,comb);
        return ans;
    }
};
