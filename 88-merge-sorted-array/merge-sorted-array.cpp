class Solution {
public:
// brute - just replace all n elemts at the end of arr1 with arr2 - then sort (o(n . logn))
// better - implement merge algo to a third arr - then arr1 = arr3
// optimal ----
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        if ( n == 0 ) return;
        if ( m == 0 ) {
            for(int it = 0; it<n ; it++ ){
                nums1[it] = nums2[it];
            }
            return;
        }

        while(j>=0 && i>=0){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums1[k]);
                i--;
                k--;
            }

            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        while(j>=0 && k>=0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        while(i>=0 && k>=0) {
            nums1[k] = nums1[i];
            k--;
            i--;
        }
    }
};