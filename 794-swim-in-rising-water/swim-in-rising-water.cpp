class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // pq {{grid[i][j],mx},{i,j}};

        priority_queue<pair<pair<int,int>,pair<int,int>>,
                vector<pair<pair<int,int>,pair<int,int>>>,
                greater<>> pq;

        pq.push({{grid[0][0],grid[0][0]},{0,0}});
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));

        while(!pq.empty()){
            auto [data,coor] = pq.top();
            pq.pop();

            int path_mx = data.second;
            int cur = data.first;

            int x = coor.first;
            int y = coor.second;

            path_mx = max(path_mx,cur);
            
            if (x==n-1 && y==n-1) return path_mx;
    
            vis[x][y] = 1;

            int dx[4] = {-1,1,0,0};
            int dy[4] = {0,0,-1,1};


            for(int i =0;i<4;i++) {
                int X = x+dx[i];
                int Y = y+dy[i];

                if(X>=0&&Y>=0&&X<n&&Y<n && (!vis[X][Y])){
                    pq.push({{grid[X][Y],path_mx},{X,Y}});
                }
            }
        }
        return 0;
    }
};