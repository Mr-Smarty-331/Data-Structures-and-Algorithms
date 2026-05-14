class Solution {
    int timer = 0;
    void dfs(int node,int parent, vector<int>& low,
            vector<int>& time,
            vector<vector<int>>& adj,
            vector<int>& vis, 
            vector<vector<int>>& ans) {
        vis[node] = 1;
        time[node] = timer;
        low[node] = timer;
        timer++;
        for(int nbr : adj[node]) {
            if (nbr == parent) continue;
            if (!vis[nbr]) {
                dfs(nbr,node,low,time,adj,vis,ans);
                low[node] = min(low[node],low[nbr]);
                if (low[nbr] > time[node]) ans.push_back({node,nbr});
            }
            else{
                low[node] = min(low[node],low[nbr]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> low(n);
        vector<int> time(n);

        vector<int> vis(n,0);
        vector<vector<int>> ans;

        dfs(0,-1,low,time,adj,vis,ans);

        return ans;
    }
};