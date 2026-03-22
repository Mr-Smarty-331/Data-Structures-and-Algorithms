class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& size) {
        sort(greed.begin(),greed.end());

        sort(size.begin(),size.end());
        int ans=0;
        
        int j=0,i=0;

        while(i<size.size()&&j<greed.size()){

            if (size[i]>=greed[j]){
                ans++;
                j++;
            }

            i++;
        }

        return ans;
    }
};