class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        stack<int> st;
        bool b=true;
        for (int i=0; i<n;i++){
            b=true;
            while(st.size() && st.top()<=abs(arr[i]) && (arr[i]<0) && b){
                if (st.top()==abs(arr[i])) {
                    b=false;
                }
                if (st.top()>0) {st.pop();}
                else{
                    break;
                }
            }
            if (st.size() && arr[i]<0 && (st.top()>abs(arr[i]))){
                continue;
            }
            if (b) st.push(arr[i]);
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};