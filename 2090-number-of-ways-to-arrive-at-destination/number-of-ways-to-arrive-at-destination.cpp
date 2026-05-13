class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            long long w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // int cnt = 0;
        // int mn = 1e9;
        long long INF = 1e18; 
        // notice the constriants taking arbitrary max as 1e9 wont suffice bc that distance can reach upto there
        vector<long long> dist(n,INF);
        dist[0] = 0;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq; // store {dist,node}

        pq.push({0,0});
        vector<int> ways(n,0);
        ways[0]=1;

        int mod = (int)(1e9 + 7);

        while(!pq.empty()) {
            auto it = pq.top();
            long long ds = it.first;
            int node = it.second;
            pq.pop();

            if (ds>dist[node]) continue;

            for(auto ad : adj[node]) {
                auto [nbr,nbrW] = ad;

                long long newD = nbrW + ds;

                if (dist[nbr] > newD) {

                    dist[nbr] = newD;

                    pq.push({(newD),nbr});

                    ways[nbr] = ways[node];
                }

                else if (dist[nbr] == newD) {
                    ways[nbr] = (ways[nbr] + ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};