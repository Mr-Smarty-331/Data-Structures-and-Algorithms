class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for(int i = 0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int num1 = nums[i];
            
            for(int j = i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int num2 = nums[j];


                int left = j+1,right = n-1;
                while(left<right){
                    int num3 = nums[left];
                    int num4 = nums[right];

                    long long sum = (long long)num1 + num2 + num3 + num4;

                    if(sum > target) right--;
                    else if(sum < target) left++;

                    else{
                        ans.push_back(vector<int> {num1,num2,num3,num4});
                        left++;
                        right--;
                        while(left<right && nums[left] == nums[left-1]) left++;
                        while(left<right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }

        return ans;
    }
};