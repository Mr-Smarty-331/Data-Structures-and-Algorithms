class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> reach(n+1,0);

        for(int i = 0;i<=n;i++){
            int left = max(0,i-ranges[i]);
            int right = min(n,i+ranges[i]);

            reach[left] = max(reach[left],right);
        }

        int max_reach = 0;
        int cur_reach = 0;
        int ans = 0;

        for(int i = 0;i<=n;i++){
            max_reach = max(max_reach,reach[i]);

            if( i == cur_reach ){
                if(max_reach>=n) return ++ans;
                
                if (cur_reach == max_reach) return -1;

                ans++;
                cur_reach = max_reach;
            }
        }

        return 0;
    }
};