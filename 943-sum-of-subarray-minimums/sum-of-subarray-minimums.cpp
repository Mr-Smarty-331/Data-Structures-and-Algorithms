class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> nse,pse;
        
        int n = arr.size();
        vector<int> vecn(n,n),vecp(n,-1);
        int mod = 1e9 + 7;
        int ans=0;
        for(int i=0;i<n;i++){
            while(nse.size()&&(arr[nse.top()]>=arr[i])){
                vecn[nse.top()]=i;
                nse.pop();
            }
            nse.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(pse.size()&&(arr[pse.top()]>arr[i])){
                vecp[pse.top()]=i;
                pse.pop();
            }
            pse.push(i);
        }
        for (int j=0;j<n;j++){

            int right = vecn[j]-j;
            int left = j-vecp[j];

            long long total= 1LL* left* right;

            int val = (total*arr[j]*1LL)%mod;

            ans= (ans+val)%mod;
        }
        return ans;
    }
};