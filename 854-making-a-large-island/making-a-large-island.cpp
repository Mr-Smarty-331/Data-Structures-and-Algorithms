class Solution {

    pair<int,int> findPar(pair<int,int> node, vector<vector<pair<int,int>>>& parent) {
        if (parent[node.first][node.second] == pair<int,int>{node.first,node.second}) return pair<int,int>{node.first,node.second};

        return parent[node.first][node.second] = findPar(parent[node.first][node.second],parent);
    }

    void unite (pair<int,int> a, pair<int,int> b, vector<vector<int>>& size,vector<vector<pair<int,int>>>& parent) {
        auto pa = findPar(a, parent);
        auto pb = findPar(b, parent);

        if (pa == pb) return;

        auto [ax, ay] = pa;
        auto [bx, by] = pb;

        if (size[ax][ay] < size[bx][by]) {
            swap(pa, pb);
            swap(ax, bx);
            swap(ay, by);
        }

        parent[bx][by] = pa;
        size[ax][ay]+=size[bx][by];
    }

public:

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(n));

        vector<vector<int>> size(n,vector<int>(n,1));

        for(int i=0;i<n;i++) {
            for (int j =0;j<n;j++) {
                parent[i][j] = {i,j};
            }
        }

        queue<pair<int,int>> zeros;
        queue<pair<int,int>> ones;

        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++) {
                if (grid[i][j] == 0) zeros.push({i,j});
                else ones.push({i,j});
            }
        }

        vector<vector<int>> vis(n,vector<int> (n,0));
        if(ones.size()==n*n) return n*n;
        while(!ones.empty()){
            auto [x,y] = ones.front();
            ones.pop();

            if (vis[x][y]) continue;

            vis[x][y] = 1;

            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};

            for (int i =0;i<4;i++) {
                int X = x+dx[i];
                int Y = y+dy[i];

                if (X>=0&&Y>=0&&X<n&&Y<n && (!vis[X][Y]) && grid[X][Y]) {
                    ones.push({X,Y});
                    unite({x,y},{X,Y},size,parent);
                }
            }
        }
        int sum = 0;


        while(!zeros.empty()){
            auto [x,y] = zeros.front();
            zeros.pop();

            if (vis[x][y]) continue;

            vis[x][y] = 1;

            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};

            set<pair<int,int>> st;
            for (int i =0;i<4;i++) {
                int X = x+dx[i];
                int Y = y+dy[i];

                if (X>=0&&Y>=0&&X<n&&Y<n && grid[X][Y]) {
                    pair<int,int> pnbr = findPar({X,Y},parent);
                    st.insert(pnbr);
                }
            }
            int h = 0;
            for(auto k : st) h+=size[k.first][k.second]; 
            sum = max(sum,h+1);
        }
        return sum;
    }
};