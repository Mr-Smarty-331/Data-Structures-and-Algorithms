class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        //we'll use the cycle detection via toposort technique

        //reverse all the edges we need the nodes with no outdegree pref.
        vector<int> indeg(V);
        vector<vector<int>> adjn(V);
        for (int i =0; i<V ; i++) {
            for (int nbr : adj[i]){
                adjn[nbr].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int z=0;z<V;z++ ) {
            if (indeg[z]==0) q.push(z);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (int nbr : adjn[node]) {
                indeg[nbr]--;
                if (indeg[nbr]==0) q.push(nbr);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};