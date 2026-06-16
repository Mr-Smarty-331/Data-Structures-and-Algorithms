class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();

        vector<int> ans;

        while(i<n&&j<m){
            if(a[i]<b[j]) i++;
            else if(b[j]<a[i]) j++;
            else{
                if(!ans.empty() && (ans.back()==a[i])) {
                    i++;
                    j++;
                    continue;
                }
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};