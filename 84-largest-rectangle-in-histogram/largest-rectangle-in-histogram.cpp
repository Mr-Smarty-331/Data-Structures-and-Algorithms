class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        int mx=0;
        for (int i=0;i<n;i++){
            int cur=arr[i];
            while(st.size()&&(arr[st.top()]>cur)){
                int r=i;
                int el=arr[st.top()];
                st.pop();
                int l=st.size()? st.top():-1;
                mx=max(mx,(r-l-1)*el);
            }
            st.push(i);
        }
        while(st.size()){
            int r=n;
            int el=arr[st.top()];
            st.pop();
            int l=st.size()? st.top():-1;
            mx=max(mx,(r-l-1)*el);
        }
        return mx;
    }
};