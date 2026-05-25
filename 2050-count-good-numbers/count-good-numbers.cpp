class Solution {
    long long mypow(int n,long long p){
        if (p == 0) return 1;
        if (p == 1) return n;
        int mod = 1e9+7;

        long long val = mypow(n,p/2);

        val = (val*val)%mod;

        if (p&1) return (val*n)%mod;
        return val;
    }
public:
    int countGoodNumbers(long long n) {
        long long ne = (n+1)/2;
        long long no = n/2;
        long long mod = 1e9+7;
        // odd places have 4 choices
        // even places have 5 choices

        long long a = mypow(5,ne);
        long long b = mypow(4,no);

        return ((1LL* a * b)%mod);
    }
};