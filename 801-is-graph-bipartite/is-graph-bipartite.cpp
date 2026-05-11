class Solution {
private:
    bool dfs(int node, int col,vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = col;
        for (int nbr : adj[node]){
            if (vis[nbr]==-1){
                if (dfs(nbr,(!col), adj, vis)==false) return false;
            }
            else if (vis[nbr]==col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,-1);

        for (int i=0;i<n;i++) {
            if (vis[i]==-1){
                if (dfs(i,0,adj,vis)==false) return false;
            }
        }

        return true;
    }
};