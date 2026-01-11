class Solution {
public:
    void func(vector<vector<int>>& ans,int k,int n, vector<int>& curr, int num){
        if(n==0&&curr.size()==k&&num<=10){
            ans.push_back(curr);
            return;
        }
        if (n<=0||curr.size()>k){
            return;
        }

        for (int i=num;i<=n;i++){
            curr.push_back(i);
            func(ans,k,n-i,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        func(ans,k,n,curr,1);
        return ans;
    }
};