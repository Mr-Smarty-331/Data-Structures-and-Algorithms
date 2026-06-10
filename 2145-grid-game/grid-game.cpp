class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pref1(n);
        vector<long long> pref2(n);
        pref1[0] = grid[0][0];
        pref2[0] = grid[1][0];

        for(int i =1;i<n;i++){
            pref1[i]=pref1[i-1]+grid[0][i];
            pref2[i]=pref2[i-1]+grid[1][i];
        }

        long long res = LLONG_MAX;
        for (int i = 0;i<n;i++){
            // deciding when the bot1 goes down

            // at index i it goes down
            // the remaining element divided into two

            long long top = pref1[n-1] - pref1[i];
            long long bottom = 0;
            if (i>0) bottom = pref2[i-1];

            // bot2 chooses max from them
            long long bot2 = (top<bottom)? bottom:top;

            // bot1 minimizes this
            res = (bot2<res)? bot2:res;
        }

        return res;
    }

};