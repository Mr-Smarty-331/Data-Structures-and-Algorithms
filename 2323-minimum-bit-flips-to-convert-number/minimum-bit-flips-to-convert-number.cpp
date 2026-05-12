class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start^goal;

        int c=0;
        while(x) {
            c++;
            x&=(x-1);
        }
        return c;
    }
};