class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        stack<vector<int>> st;
        st.push(arr[0]);
        for(int i = 1;i<n;i++){
            vector<int> last = st.top();
            if (last[1]>=arr[i][0]){ // cur starts earlier than last ends
                // the intervals overlap 
                // if curr ends later than last end - we'll merge the intervals
                if(arr[i][1]>=last[1]){
                    // kya kare ab - 
                    // replace lasts second value with this intervals second value

                    st.pop();
                    last[1] = arr[i][1];
                    st.push(last);
                }
                else{
                    continue;
                }
            }
            else{
                st.push(arr[i]);
            }
        }

        int m = st.size();
        vector<vector<int>> ans(m);
        for(int i = m-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};