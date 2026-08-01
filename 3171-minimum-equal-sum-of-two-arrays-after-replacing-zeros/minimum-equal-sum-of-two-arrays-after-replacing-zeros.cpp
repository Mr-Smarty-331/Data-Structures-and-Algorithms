class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long n1 = nums1.size();
        long long n2 = nums2.size();

        long long nz1 = 0,nz2 = 0;

        long long s1 = 0,s2 = 0;
        for(long long x : nums1) {
            if (!x) nz1++;
            s1+=x;
        }

        for(long long x : nums2) {
            if (!x) nz2++;
            s2+=x;
        }
        long long minReach;
        long long lesser;
        long long mrZ;
        long long lZ;

        if((nz1+s1<nz2+s2)) {
            minReach = nz2+s2;
            lesser = nz1+s1;
            mrZ = nz2;
            lZ = nz1;
        }
        else {
            minReach = nz1+s1;
            lesser = nz2 + s2;
            mrZ = nz1;
            lZ = nz2;
        }



        if (lesser!=minReach && lZ==0) return -1;
        return minReach;
    }
};