class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool val = false;
        
        if (!n) return false;

        int c = 0;
        while (n) {
            if (c>=1) {
                return false;
            }
            if(n&1) c++;
            n = n>>1;
        }
        return true;
    }
};