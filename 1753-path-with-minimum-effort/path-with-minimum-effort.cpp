class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue< 
                pair<int,pair<int,int>> ,
                vector<pair<int,pair<int,int>>> , 
                greater<> > 
                pq;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m,vector<int> (n,1e9));
        dist[0][0] = 0;


        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int x = node.second.first;
            int y = node.second.second;
            int diff = node.first;

            pair<int,int> dir[4] = {{x-1,y},{x,y-1}, {x,y+1},{x+1,y}};

            if (x==m-1 && y==n-1) return diff;

            if (diff > dist[x][y]) continue;

            for (auto move : dir){
                int X = move.first;
                int Y = move.second;

                if (X>=0 && Y>=0 && X <m && Y<n) {
                    int newD = max(abs(grid[X][Y] - grid[x][y]),diff);

                    if (newD < dist[X][Y]){
                        dist[X][Y]=newD;
                        pq.push({newD,{X,Y}});
                    }
                }
            }


        }
        return 0;
    }
};