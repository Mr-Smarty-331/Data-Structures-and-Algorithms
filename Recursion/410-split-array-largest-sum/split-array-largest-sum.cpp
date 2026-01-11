class Solution {
public:
    int check(int m,int k,vector<int> arr){
        int count=1;
        int sum=0;
        for (int i=0;i<arr.size();i++){
            if (sum+arr[i]>m) {sum=0;count++;}
            sum+=arr[i];
            // if (count>k) return 0;
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=INT_MIN;
        int h=0;

        for(int x:nums){
            h+=x;
            l=max(l,x);
        }
        int m;
        while(l<=h){
            m=(l+h)/2;
            if (check(m,k,nums)>k) l=m+1;
            else h=m-1;
        }
        return l;
    }
};