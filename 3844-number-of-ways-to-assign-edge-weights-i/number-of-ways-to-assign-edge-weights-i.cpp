class Solution {
    int M = 1e9+7;
    int dfs(int node,int par,vector<vector<int>> &subtree){
        if(subtree[node].size() == 1 && par!=-1) return 0;

        // going thru all the children of this node
        int path = 0;
        for(int nbr : subtree[node]){
            if(nbr == par) continue;

            path = max(path,1+dfs(nbr,node,subtree));
        }
        return path;
    }
    vector<int> dp;
    int pow_two(int n){
        if( n==0 ) return 1;
        if( n==1 ) return 2;
        if(dp[n]!=-1) return dp[n];
        long long val = (pow_two(n/2));
        val = (val*val)%M;

        long long ans = val;
        if (n&1) ans = (ans*2)%M;

        return dp[n] = ans;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> subtree(n+1); // one index shift
        for(auto e : edges){
            subtree[e[0]].push_back(e[1]);
            subtree[e[1]].push_back(e[0]);
        }

        // finding the maximum depth
        int k = dfs(1,-1,subtree); // k = max_path
        dp.resize(k,-1);
        // ans = no. of ways of choosing 1s (odd no of it) in max_path items
        // 1ck + 3ck + 5ck + .... + (k or k-1)ck;

        return pow_two(k-1);
    }
};