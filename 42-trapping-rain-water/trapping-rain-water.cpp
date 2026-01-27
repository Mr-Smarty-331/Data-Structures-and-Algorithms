class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> post_max(n);
        int pre_max=0;
        int mx=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,height[i]);
            post_max[i]=mx;
        }
        int area=0;
        for(int j=0;j<n;j++){
            if (height[j]>pre_max){
                pre_max=height[j];
            }
            int mn=min(pre_max,post_max[j]);
            if (height[j]<=mn){
                area+=mn-height[j];
            }
        }
        return area;
    }
};