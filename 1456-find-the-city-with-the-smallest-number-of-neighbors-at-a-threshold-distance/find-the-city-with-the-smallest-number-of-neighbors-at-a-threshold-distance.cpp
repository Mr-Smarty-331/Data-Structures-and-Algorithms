class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>> dist(n,vector<int>(n,1e8)); 

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[u][v]=w;
            dist[v][u]=w;
        }

        for (int i=0 ; i<n ; i++) {
            dist[i][i] = 0;
        }

        for (int v = 0;v<n;v++){
            for (int i = 0; i<n ; i++){
                for (int j = 0; j<n ; j++){
                    if ((dist[i][v]==1e8)||(dist[v][j]==1e8)) continue;
                    dist[i][j] = min ((dist[i][v] + dist[v][j]), dist[i][j]);
                }
            }
        }

        int mn1=n+1;
        int mn2=n+1;

        for(int i=0;i<n;i++) {
            int c=0;
            
            for (int j =0;j<n;j++) {
                if (dist[i][j] <= th){
                    c++;
                }
            }

            if (c<=mn1) {
                mn1 = c;
                mn2 = i;
            }
        }
        return mn2;
    }
};