class Solution {
private: 
    bool check(int x,int y, int m, int n , vector<vector<int>>& grid) {
        return (x>=0&&y>=0&&x<m&&y<n && grid[x][y]==0);
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]!=0) return -1;
        //I'll fkn use dijkstras over here
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>> 
            pq;

        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0] = 1;

        pq.push({1,{0,0}});

        while(!pq.empty()){
            auto node  = pq.top();
            pq.pop();
            int d = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if (x==m-1&&y==n-1) return d;

            if (d>dist[x][y]) continue;

            int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
            int dy[8] = {-1,  0,  1, -1, 1,-1, 0, 1};

            for (int i=0;i<8;i++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if (check(X,Y,m,n,grid)) {
                    if (dist[x][y] + 1 < dist[X][Y]) {
                        dist[X][Y] = dist[x][y] + 1;
                        pq.push({dist[X][Y],{X,Y}});
                    }
                }
            }
        }
        return -1;
    }
};