class Solution {
private: 
    bool isCycle(int node, vector<int>& visited, vector<int>& path, vector<int> adj[]){
        visited[node]=1;
        path[node]=1;

        for(int nbr: adj[node]){
            if (!visited[nbr]){
                if (isCycle(nbr,visited,path,adj)) return true;
            }

            else if(path[nbr]) return true;
        }

        path[node]=0;
        return false;
    }

public:
    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<int> visited(v,0);
        vector<int> path(v,0);

        vector<int> adj[v];
        for (auto e:edges){
            adj[e[1]].push_back(e[0]);
        }

        for (int i=0;i<v;i++){
            if (!visited[i]){
                if (isCycle(i,visited,path,adj)==true) return false;
            }
        }
        return true;
    }
};