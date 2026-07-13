class Solution {
    int cnt = 0;

    void sort(int low, int high, vector<int> &arr) {
        if (low>=high) return;
        int mid = (low+high)/2;
        
        sort(low,mid,arr);
        sort(mid+1,high,arr);
        
        merge(low,mid,high,arr);
    }
    
    void merge(int low,int mid, int high, vector<int> &arr) {
        if (low >= high) return;
        vector<int> temp;       
        
        int left = low;
        int right = mid+1;

        int i = low;
        int j = mid+1;

        // [2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647]

        while(i<=mid) {
            while(i<=mid && j<=high && (1LL*arr[i]>2LL*arr[j])){
                j++;
            }
            cnt+=j-mid-1;
            i++;
        }
        
        while(left<=mid&&right<=high){
            if (arr[left]>arr[right]){
                temp.push_back(arr[right]);
                right++;
            }
            else{
                temp.push_back(arr[left]);
                left++;
            }
        }
        
        while(left<=mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        sort(0,n-1,nums);

        return cnt;
    }
};