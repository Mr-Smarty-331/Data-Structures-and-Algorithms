class Solution {
public:
    void func(vector<int>& cdd ,int k, int ind, vector<vector<int>>& ans,vector<int>& curr){
        if (ind==cdd.size()||k<0){
            if (k==0){
                ans.push_back(curr);
                return;
            }
            return;
        }
        if (cdd[ind]<=k){
            curr.push_back(cdd[ind]);
            func(cdd,k-cdd[ind],ind,ans,curr);
            curr.pop_back();
        }
        
        // curr.pop_back(); 
        func(cdd,k,ind+1,ans,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        func(candidates,target,0,ans,curr);
        return ans;
    }
};