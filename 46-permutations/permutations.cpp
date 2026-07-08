class Solution {
    vector<vector<int>> ans;
    void bfs(vector<int> &nums, vector<int> &cur,vector<int>& vis){
        int n = nums.size();

        if(cur.size()==n){
            ans.push_back(cur);
            return;
        }

        for(int i = 0;i<n;i++){
            if(vis[i]) continue;
            vis[i] = 1;
            cur.push_back(nums[i]);

            bfs(nums,cur,vis);

            vis[i] = 0;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> vis(n,0);
        vector<int> cur;
        bfs(nums,cur,vis);

        return ans;
    }
};