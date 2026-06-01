class Solution {
    void init(vector<int>& cost){

    }
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        int ans = 0;
        int i = n-1;
        while(i-2>=0){
            ans += cost[i] + cost[i-1];
            i-=3;
        }
        while(i>=0){
            ans+=cost[i];
            i--;
        }
        return ans;
    }
};