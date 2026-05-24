class Solution {
    map<int,long long> memo;
    long long twos(int n){
        if(n==1) return 2;
        if(n==0) return 1;

        if (memo.count(n)) return memo[n];
        long long mod = 1e9 + 7;
        long long t = (twos(n/2));
        t = (t*t)%mod;
        if (n&1) return memo[n] = (t*2)%mod;
        else return memo[n] = (t)%mod;
    }
public:
    int monkeyMove(int n) {
        int val = twos(n) - 2;
        cout<<val;
        return (val < 0)? (1e9 + 7 + val):val;
    }
};