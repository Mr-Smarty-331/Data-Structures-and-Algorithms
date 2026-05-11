class Solution {
private: 
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, vector<int>& ans){
        path[node]=1;
        vis[node]=1;

        for(int nbr : adj[node]) {
            if (!vis[nbr]) {
                if (dfs(nbr,adj,vis,path,ans)==false) return false;
            }
            else if (path[nbr]) return false;
        }
        
        path[node]=0;
        ans.push_back(node);
        return true;
    }
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> path(n,0);

        for(int i=0;i<n;i++){
            if (!vis[i]) {
                dfs(i,adj,vis, path, ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};