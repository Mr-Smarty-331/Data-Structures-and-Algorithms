class Solution {
private:
    int findPar(int x,unordered_map<int,int>& parent){
        if (parent.find(x)==parent.end()){
            parent[x] = x;
        }

        if (parent[x]!=x) parent[x] = findPar(parent[x],parent);

        return parent[x];
    }

    void unite (int a,int b,unordered_map<int,int>& parent) {
        parent[findPar(a,parent)] = findPar(b,parent);
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int maxR =0;
        int maxC =0;

        for(auto it : stones) {
            maxR = max(maxR,it[0]);
            maxC = max(maxC,it[1]);
        }

        unordered_map<int,int> parent;

        for (auto it: stones) {
            int a = it[0];
            int b = it[1];
            unite(a,b+maxR+1,parent);
        }

        unordered_set<int> st;

        for (auto stone : stones){
            st.insert(findPar(stone[0],parent));
        }

        return stones.size() - st.size();
    }
};