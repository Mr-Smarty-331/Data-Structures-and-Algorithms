class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj[0].size();
        int cnt=0;
        queue<int> q;
        vector<bool> visited(n,false);

        for (int i=0;i<n;i++){

            if (!visited[i]){
                cnt++;
                q.push(i);
                visited[i]=1;

                while(!q.empty()){
                    int node=q.front();
                    q.pop();

                    for (int j=0;j<n;j++){
                        bool isnbr=adj[node][j];
                        if (isnbr==1){
                            int nbr = j;
                            if (!visited[nbr]) {
                                q.push(nbr);
                                visited[nbr]=1;
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};