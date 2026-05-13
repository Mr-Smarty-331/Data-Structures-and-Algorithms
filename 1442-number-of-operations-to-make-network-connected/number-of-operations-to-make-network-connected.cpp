class Solution {
    int find(int u, vector<int>& parent){
        if (u == parent[u]) return u;

        return parent[u] = find(parent[u],parent);
    }

    void unite(int u, int v,vector<int>& parent,vector<int>& size){
        int pu=find(u,parent);
        int pv=find(v,parent);

        if (pv == pu) return;
        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
        else {
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        if (edges.size() < n-1) return -1;

        // we need number of steps to make mst out of the graph
        // simply the number of connected component-1

        vector<int> parent(n);
        vector<int> size(n,1);

        for (int i=0;i<n;i++) {
            parent[i] = i;
        }

        for (auto e : edges) {
            unite(e[0],e[1],parent,size);
        }

        set<int> st;

        for (int i=0; i<n ;i++) {
            st.insert(find(i,parent));
        }

        return st.size()-1;

    }
};