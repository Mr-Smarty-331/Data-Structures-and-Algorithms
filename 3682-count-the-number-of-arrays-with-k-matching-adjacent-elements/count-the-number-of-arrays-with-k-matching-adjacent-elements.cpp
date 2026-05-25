class Solution {
    map<pair<int,int>,int> pow;
    int mod  = 1e9+7;
    vector<long long> fac,invfac;

    // long long fac(int n){
    //     if (n<2) return 1;
    //     if (fc.count(n)) return fc[n];
    //     int mod = 1e9+7;
    //     return fc[n] = ((n%mod)*fac(n-1))%mod;
    // }

    long long C(int n,int k){
        
        return (((fac[n]*invfac[k])%mod)*invfac[n-k])%mod;
    }

    void init(int n){
        fac.resize(n+1);
        invfac.resize(n+1);
        fac[0] = 1;
        for(int i = 1;i<=n;i++){
            fac[i]=(1LL*i*fac[i-1])%mod;
        }

        invfac[n] = mypow(fac[n],mod-2);
        for(int i = n-1;i>=0;i--){
            invfac[i]=(1LL*(i+1)*invfac[i+1])%mod;
        }
    }

    long long mypow(int n,int p){
        if (n == 0 && p==0) return 1;
        if (p==0) return 1;
        if (p==1) return n;

        if (pow.count({n,p})) return pow[{n,p}];

        long long val = mypow(n,p/2);
        val = (val*val)%mod;

        return pow[{n,p}] = (p&1)? (val*(n%mod))%mod : val;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        init(n);
        long long pairs = C(n-1,k);

        long long prod = (1LL*m*mypow(m-1,n-1-k))%mod;
        cout<<prod<<" "<<pairs;
        long long ans = (pairs*prod)%mod;
        return ans;
    }
};