class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();

        vector<int> vec(n,1);

        for(int i = 1;i<n;i++){
            if (arr[i] > arr[i-1]) {
                vec[i] = 1+vec[i-1];
            }
        }

        for(int i = n-2;i>=0;i--){
            if (arr[i] > arr[i+1]) {
                vec[i] = max(1+vec[i+1],vec[i]);
            }
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt+=vec[i];
        }

        return cnt;
    }
};