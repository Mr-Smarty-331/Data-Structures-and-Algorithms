class Solution {
    
    int myPow(int n,int p){
        int mod = 1337;
        if (n<=1) return n%mod;
        if (p==1) return n%mod;
        if (p==0) return 1;

        long long val = myPow(n,p/2);
        val = (val*val)%mod;

        if (p&1){
            return (val*(n%mod))%mod;
        }
        return val;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (a<=1) return a;
        int n = b.size();
        long long ans = 1;
        long long mod = 1337;

        for(int i=0;i<n;i++){

            ans *= myPow(a,b[i]);
            ans %=mod;

            if (i<n-1){

                ans = (myPow(ans,10));

            }

        }

        return ans;
    }
};