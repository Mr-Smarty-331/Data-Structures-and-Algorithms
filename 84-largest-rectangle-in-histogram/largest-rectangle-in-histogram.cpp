class Solution {
public:
    vector<int> findPse(vector<int>& arr){
        int n=arr.size();
        vector<int> vec(n,-1);
        stack<int> st;
        for (int i=0;i<n;i++){
            int cur=arr[i];
            while(st.size()&&(arr[st.top()]>=cur)){
                st.pop();
            }
            if (st.size()) vec[i]=st.top();
            st.push(i);
        }
        return vec;
    }
    vector<int> findNse(vector<int>& arr){
        int n=arr.size();
        vector<int> vec(n,n);
        stack<int> st;
        for (int i=n-1;i>=0;i--){
            int cur=arr[i];
            while(st.size()&&(arr[st.top()]>=cur)){
                st.pop();
            }
            if (st.size()) vec[i]=st.top();
            st.push(i);
        }
        return vec;
    }


    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=findNse(arr);
        vector<int> pse=findPse(arr);
        int mx=0;
        for(int i=0;i<n;i++){
            int area=arr[i]*(nse[i]-pse[i]-1);
            mx=max(mx,area);
        }
        return mx;
    }
};