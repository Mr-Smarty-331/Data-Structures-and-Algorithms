class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
        }

        vector<int> dist(n,1e9);
        dist[src] = 0;

        // priority_queue<
            // pair<pair<int,int>,int>, 
            // vector<pair<pair<int,int>,int>>, 
            // greater<>> pq;

        queue<pair<pair<int,int>,int>> q;

        q.push({{0,0},src});

        while(!q.empty()) {
            int st = q.front().first.second;
            int d = q.front().first.first;
            int node = q.front().second;
            q.pop();

            if (st > k) continue;

            for (auto it : adj[node]) {
                int nbr = it.first;
                int wt = it.second;

                if (dist[nbr] > d + wt && st<=k) {
                    dist[nbr] = d + wt;
                    q.push({{dist[nbr],st+1},nbr});
                }
            }
        }
        if (dist[dst]!=1e9) return dist[dst];
        return -1;
    }

};