class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& size) {
        sort(greed.begin(),greed.end());

        sort(size.begin(),size.end());
        int ans=0;
        
        int j=0;

        for(int i=0;i<size.size();i++){
            if(j>=greed.size()) break;
            if (size[i]>=greed[j]){
                ans++;
                j++;
            }
        }

        return ans;
    }
};