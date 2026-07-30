class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // bs to find index of largest num less than 0 (lower_bound)
        int low = 0;
        int high = n-1;
        int l_ind = -1;

        while(low<=high){
            int mid = (low+high+1)/2 ;

            if(nums[mid] < 0){
                // can go further left
                low = mid+1;
                l_ind = mid;
            }

            else{
                high = mid-1;
            }
        }

        // bs to find index of smallest num greater than 0 (upper_bound)
        low = 0;
        high = n-1;
        int s_ind = -1;

        while(low<=high){
            int mid = (low+high+1)/2 ;

            if(nums[mid] > 0){
                // can go further left
                high = mid-1;
                s_ind = mid;
            }

            else{
                low = mid+1;
            }
        }

        int neg = 0;
        int pos = 0;

        if (l_ind!=-1) neg = l_ind+1;
        if (s_ind!=-1) pos = n-s_ind;

        return max(neg,pos);
    }
};