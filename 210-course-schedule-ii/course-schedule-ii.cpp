class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        //we'll do this via kahn's algorithm

        vector<vector<int>> adj(V);
        vector<int> indeg(V);
        for(auto it : edges) {
            adj[it[1]].push_back(it[0]);
            //creating indegree list for all the nodes
            indeg[it[0]]++;
        }
        //adjacency list created

        queue<int> q;

        for (int i=0;i<V;i++) {
            if (indeg[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int nbr : adj[node]){
                indeg[nbr]--;
                if (indeg[nbr]==0) {
                    q.push(nbr);
                }
            }
        }

        if (ans.size()==V) return ans;
        return vector<int> {};
    }
};