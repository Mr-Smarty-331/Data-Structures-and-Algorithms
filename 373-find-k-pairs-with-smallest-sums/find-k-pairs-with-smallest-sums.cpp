class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        set<pair<int,int>> vis;
        vis.insert({0,0});
        pq.push({a[0]+b[0],{0,0}});

        int i=0;
        int n = a.size();
        int m = b.size();

        vector<vector<int>> ans;
        while(i<k){
            auto [sum,cd] = pq.top();
            auto [x,y] = cd;
            pq.pop();

            ans.push_back({a[x],b[y]});

            if (x+1 <n && (!vis.count({x+1,y}))) {
                vis.insert({x+1,y});
                pq.push({a[x+1]+b[y],{x+1,y}});
            }
            if (y+1 <m && (!vis.count({x,y+1}))) {
                vis.insert({x,1+y});
                pq.push({a[x]+b[y+1],{x,1+y}});
            }
            i++;
        }

        return ans;
    }
};