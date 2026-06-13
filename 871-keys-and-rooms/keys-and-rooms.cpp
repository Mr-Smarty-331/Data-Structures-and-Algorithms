class Solution {
    void dfs(int i, vector<int>& vis, vector<vector<int>>& rooms){
        vis[i] = 1;
        for (int nbr : rooms[i]){
            if(!vis[nbr]) dfs(nbr,vis,rooms);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> vis(n,0);

        dfs(0,vis,rooms);

        for(int been : vis){
            if(!been) return false;
        }

        return true;
    }
};