class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (mat[i][j]==0) {
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){

            int s = q.size();

            for (int i=0;i<s;i++){
                int x = q.front().first.first;
                int y = q.front().first.second;

                int d = q.front().second;

                q.pop();

                if (!vis[x][y]){
                    vis[x][y]=1;
                    ans[x][y]=d;

                    pair<int,int> dir[4] = {{x-1,y},{x,y-1}, {x+1,y}, {x,y+1}};

                    for (auto& it : dir){
                        int X = it.first;
                        int Y = it.second;

                        if ((X>=0&&X<m)&&(Y>=0&&Y<n)&&(!vis[X][Y])&&(mat[X][Y]==1)) {
                            q.push({{X,Y},d+1});                            
                        }
                    }

                }
                if (mat[x][y]==0){

                }
            }
        }
        return ans;
    }
};