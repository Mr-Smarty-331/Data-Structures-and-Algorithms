class Solution {
public:
    //Ayush
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i=0;i<2*n;i++){
            int idx=i%n;
            while(st.size()&&nums[st.top()]<nums[idx]){
                ans[st.top()]=nums[idx];
                st.pop();
            }
            if(i<n){
                st.push(idx);
            }
        }
        return ans;
    }
};