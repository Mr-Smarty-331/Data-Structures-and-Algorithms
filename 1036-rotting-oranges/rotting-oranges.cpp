class Solution {
public:
    int orangesRotting(vector<vector<int>>& adj) {
        int m=adj.size();
        int n=adj[0].size();
        int total=0;
        int rot=0;

        queue<pair<int,int>> q;

        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (adj[i][j]!=0) {
                    total++;
                    if (adj[i][j]==2){
                        rot++;
                        q.push({i,j});
                    }
                }
            }
        }
        // cout<<q.front().first<<" "<<q.front().second<<" "<<total<<" "<<rot;

        int time=0;

        while(!q.empty()){
            int s=q.size();

            for (int k=0;k<s;k++){
                pair<int,int> p=q.front();

                int x=p.first;
                int y=p.second;

                pair<int,int> nbrs[4]={{x-1,y},{x,y+1},{x+1,y},{x,y-1}};

                for (int i=0;i<4;i++){

                    int X=nbrs[i].first;
                    int Y=nbrs[i].second;

                    if ((X>=0&&X<m) && (Y>=0&&Y<n) && adj[X][Y]==1){
                        adj[X][Y]=2;
                        q.push({X,Y});
                        rot++;
                    }
                }

                q.pop();
            }
            time++;
        }

        if (rot!=total) return -1;
        if (total==0) return 0;
        return time-1;
    }
};