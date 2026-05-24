class Solution {
    map<pair<double,int>,double> memo;
public:
    double myPow(double x, long long n) {
        if (x == 0) return 0;

        bool frac = (n<0);

        if (abs(n)==1) {
            double val = x;
            if (frac) val = double(1.0/x);
            return val;
        }
        if (n==0) return 1;

        if (memo.count({x,n})) return memo[{x,n}];

        bool pos = (x>=0);
        x = abs(x);

        if (n&1){
            double val = x;
            if (frac) val = double(1.0/x);
            double ans = myPow(x,n/2)*myPow(x,n/2)*val;
            return memo[{x,n}] = (pos==true)? ans:(-1)*ans;
        }
        else return memo[{x,n}] = myPow(x,n/2)*myPow(x,n/2);
    }
};