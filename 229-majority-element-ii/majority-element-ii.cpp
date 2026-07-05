class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int,pair<int,int>> hash;
        int n = nums.size();

        vector<int> ans;
        
        int cdd1 = INT_MIN;
        int cdd2 = INT_MIN;

        int v1=0,v2=0;

        for(int i = 0;i<n;i++){
            if (nums[i] == cdd1) {
                v1++;
            }
            else if (nums[i] == cdd2) {
                v2++;
            }
            else if (v1 == 0) {
                cdd1 = nums[i];
                v1 = 1;
            }
            else if (v2 == 0){
                cdd2 = nums[i];
                v2 = 1;
            }

            else {v1--;v2--;}
        }

        int vote1 = 0,vote2 = 0;

        for (int num : nums){
            if(num == cdd1) vote1++;
            else if(num == cdd2) vote2++;
        }

        cout<<cdd1<<" "<<cdd2;

        if(vote1>n/3) ans.push_back(cdd1);
        if(vote2>n/3) ans.push_back(cdd2);

        return ans;
    }
};