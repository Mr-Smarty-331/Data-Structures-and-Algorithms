class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        vector<int> dist(n+1,1e9);

        dist[k] = 0;
        dist[0] = 0;

        vector<vector<pair<int,int>>> adj(n+1);
        for (auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }

        pq.push({0,k});

        while(!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int d = it.first;
            pq.pop();

            if (d > dist[node]) continue;

            for (auto ad : adj[node]) {
                int nbr = ad.first;
                int wt = ad.second;

                if (dist[nbr] > d + wt) {
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr],nbr});
                    cout<<dist[nbr];
                }
            }
        }
        int mx = 0 ;
        for (int X : dist) {
            if (X == 1e9) return -1;
            mx = max(mx,X);
        }
        return mx;
    }
};